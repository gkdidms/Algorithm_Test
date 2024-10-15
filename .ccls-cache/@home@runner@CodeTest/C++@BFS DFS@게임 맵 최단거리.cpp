#include<vector>
#include<queue>

using namespace std;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int bfs(int x, int y, vector<vector<int>>& maps)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    int n = maps.size();
    int m = maps[0].size();

    while(!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i =0; i < 4; ++i)
        {
            int dx = xx + nx[i];
            int dy = yy + ny[i];

            if (dx < 0 || dx >= n || dy < 0 || dy >= m)
                continue;

            if (maps[dx][dy] == 0)
                continue;

            if (maps[dx][dy] == 1)
            {
                maps[dx][dy] = maps[xx][yy] + 1;
                q.push(make_pair(dx, dy));
            }
        }
    }

    if (maps[n - 1][m - 1] == 1)
        return -1;

    return maps[n - 1][m - 1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    answer = bfs(0, 0, maps);

    return answer;
}