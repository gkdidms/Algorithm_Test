#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int x, y, cnt, k;
};

int dx[12] = { -1, 1, 0, 0, -2, -2, 2, 2, -1, 1, -1, 1};
int dy[12] = { 0, 0, -1, 1, -1, 1, -1, 1, -2, -2, 2, 2};
vector<vector<int>> graph;
vector<vector<vector<bool>>> visible;

int k, n, m;

int bfs()
{
    queue<node> q;
    visible[0][0][0] = true;
    q.push({ 0, 0, 0, 0 });


    while (!q.empty())
    {
        node nd = q.front();
        q.pop();

        if (nd.x == n - 1 && nd.y == m - 1)
            return nd.cnt;

        for (int i = 0; i < 12; ++i)
        {
            int nx = nd.x + dx[i];
            int ny = nd.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == 1) continue;
            if (i > 3 && nd.k == k) continue;
            if ((i > 3 && visible[nx][ny][nd.k + 1]) || (i < 4 && visible[nx][ny][nd.k])) continue;

            if (i > 3)
                visible[nx][ny][nd.k + 1] = true;
            else 
                visible[nx][ny][nd.k] = true;

            q.push({ nx, ny, nd.cnt + 1, i < 4 ? nd.k : nd.k + 1});
        }
    }

    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    cin >> k;
    cin >> m >> n;

    graph.resize(n, vector<int>(m));
    visible.resize(n, vector<vector<bool>>(m, vector<bool>(k + 1)));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> graph[i][j];
    }

    int answer = bfs();

    cout << answer;
}