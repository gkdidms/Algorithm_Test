#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int x, y;
pair<int, int> startPos;

vector<string> graph;
queue<pair<int, int>> q_fire;
queue<pair<int, int>> q_move;

void update_fire()
{
    int size = q_fire.size();
    for (int i = 0; i < size; ++i)
    {
        pair<int, int> n = q_fire.front();
        q_fire.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = n.first + dx[i];
            int ny = n.second + dy[i];

            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;

            if (graph[nx][ny] == '.')
            {
                graph[nx][ny] = '*';
                q_fire.push({ nx, ny });
            }
        }
    }
}


int bfs()
{
    vector<vector<bool>> visible(x, vector<bool>(y));

    int time = 0;
    while (!q_move.empty())
    {
        update_fire();

        time++;

        int size = q_move.size();
        for (int i = 0; i < size; ++i)
        {
            pair<int, int> r = q_move.front();
            q_move.pop();

            if (r.first == 0 || r.second == 0 || r.first == x - 1 || r.second == y - 1)
                return time;

            for (int j = 0; j < 4; ++j)
            {
                int nx = r.first + dx[j];
                int ny = r.second + dy[j];

                if (nx < 0 || nx >= x || ny < 0 || ny >= y || visible[nx][ny]) continue;

                if (graph[nx][ny] == '.')
                {
                    visible[nx][ny] = true;
                    graph[nx][ny] = '@';
                    q_move.push({ nx, ny });
                }
            }
        }
    }

    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> y >> x;

        graph.clear();
        graph.resize(x);

        while (!q_fire.empty())
            q_fire.pop();

        while (!q_move.empty())
            q_move.pop();

        for (int i = 0; i < x; ++i)
        {
            cin >> graph[i];

            for (int j = 0; j < y; ++j)
            {
                if (graph[i][j] == '@')
                    q_move.push({ i, j });
                else if (graph[i][j] == '*')
                    q_fire.push({ i, j });
            }
        }

        int answer = bfs();

        if (answer == -1)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << answer << '\n';
    }
}