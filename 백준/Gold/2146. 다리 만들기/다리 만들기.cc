#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n;
int bridge = 0;
int answer = int(1e9);
vector<vector<int>> graph;
vector<vector<bool>> visible;
map<int, vector<pair<int, int>>> m;

void init()
{
    visible.clear();
    visible.resize(n, vector<bool>(n));
}

int bfs(int x, int y)
{
    if (visible[x][y] || graph[x][y] == 0) return 0;

    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty())
    {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        int cnt = 0;
        for (int i = 0; i < 4; ++i)
        {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visible[nx][ny]) continue;

            if (graph[nx][ny] == 0)
            {
                cnt++;
                continue;
            }
                
            visible[nx][ny] = true;
            q.push({ nx, ny });
        }

        if (cnt >= 1)
            m[bridge].push_back({ qx,qy });
    }

    return 1;
}

void check_bridge(int a, int b)
{
    for (auto am : m[a])
    {
        for (auto bm : m[b])
        {
            answer = min(answer, abs(am.first - bm.first) + abs(am.second - bm.second) - 1);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;

    graph.resize(n, vector<int>(n));
    init();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            bridge += bfs(i, j);
        }
    }

    //외곽선끼리 비교하기

    for (int i = bridge - 1; i >= 1; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            check_bridge(i, j);
        }
    }

    cout << answer;
}