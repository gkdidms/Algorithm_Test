#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int n, k;
int answer = 0;

int dx[2] = { -1, 1 };

void bfs()
{
    vector<vector<bool>> visible(100001, vector<bool>(3));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, n }); // cnt, node

    while (!q.empty())
    {
        pair<int, int> n = q.top();
        q.pop();

        if (n.second == k)
        {
            answer = n.first;
            return;
        }

        for (int i = 0; i < 3; ++i)
        {
            int m = n.second;
            if (i == 0)
                m *= 2;
            else
                m += dx[i - 1];

            if (m < 0 || m > 100000 || visible[m][i]) continue;

            visible[m][i] = true;
            q.push({i == 0 ? n.first: n.first + 1, m });
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> k;

    bfs();

    cout << answer;
}