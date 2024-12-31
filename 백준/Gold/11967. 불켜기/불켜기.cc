#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

vector<vector<vector<pair<int, int>>>> graph;
vector<vector<int>> room;
vector<vector<bool>> visible;
queue<pair<int, int>> q;

int n, m;
int answer = 1;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void switch_room(int x, int y)
{
    if (graph[x][y].size() == 0)
        return;
    
    for (auto a : graph[x][y])
    {
        if (!room[a.first][a.second])
        {
            room[a.first][a.second] = 1;
            answer++;

            for (int i = 0; i < 4; ++i)
            {
                int nx = dx[i] + a.first;
                int ny = dy[i] + a.second;

                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

                if (visible[nx][ny])
                {
                    q.push({ a.first, a.second });
                    visible[a.first][a.second] = true;
                    break;
                }
            }
        }
    }
}

void bfs()
{
    visible[1][1] = true;
    room[1][1] = true;

    q.push({1, 1});

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        switch_room(pos.first, pos.second);

        for (int i = 0; i < 4; ++i)
        {
            int nx = dx[i] + pos.first;
            int ny = dy[i] + pos.second;

            if (nx < 1 || nx > n || ny < 1 || ny > n || visible[nx][ny] || room[nx][ny] == 0) continue;

            q.push({nx, ny});    
            visible[nx][ny] = true;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;
    graph.resize(n + 1, vector<vector<pair<int, int>>>(n + 1));
    room.resize(n + 1, vector<int>(n + 1));
    visible.resize(n + 1, vector<bool>(n + 1));

    for (int i = 0; i < m; ++i)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        graph[x][y].push_back({ a, b });
    }

    bfs();

    cout << answer;
}