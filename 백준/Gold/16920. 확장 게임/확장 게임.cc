#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct node {
    int x, y, cnt;
};


int n, m, p;
vector<int> s;
vector<int> answer;
vector<queue<node>> players;
vector<vector<int>> graph;


//true 이면 더이상 확장 불가능 / false 이면 확장 가능.
bool bfs(int player)
{
    bool isSuccess = true;
    queue<node> q = players[player];
    queue<node> change;
    while (!q.empty())
    {
        node a = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a.cnt == 0) continue;

            if (graph[nx][ny] == 0)
            {
                isSuccess = false;

                graph[nx][ny] = player;
                q.push({ nx, ny, a.cnt - 1 });
                change.push({ nx, ny, s[player] });
                answer[player]++;
            }
        }
    }

    players[player] = change;

    return isSuccess;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m >> p;
    s.resize(p + 1);
    answer.resize(p + 1);
    graph.resize(n, vector<int>(m));
    players.resize(p + 1);

    for (int i = 1; i <= p; ++i)
        cin >> s[i];

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); ++j)
        {
            if (str[j] == '#')
                graph[i][j] = -1;
            else if (str[j] == '.')
                graph[i][j] = 0;
            else
            {
                graph[i][j] = str[j] - '0';
                players[graph[i][j]].push({ i, j, s[graph[i][j]]});
                answer[graph[i][j]]++;
            }
        }
    }

    while (true)
    {
        vector<bool> isFinished(p + 1);
        isFinished[0] = true;
        for (int i = 1; i <= p; ++i)
        {
            isFinished[i] = bfs(i);
        }

        bool isTrue = true;
        for (auto a : isFinished)
            if (a == false)
                isTrue = false;

        if (isTrue) break;
    }

    for (int i = 1; i <= p; ++i)
        cout << answer[i] << " ";
}