#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<char>> graph;

void cycle(int n, int dir, vector<bool>& visible)
{
    if (visible[n] || n < 0 || n > 4) return;

    visible[n] = true;
    if (n != 4 && graph[n][2] != graph[n + 1][6])
        cycle(n + 1, dir * -1, visible);
    if (n != 1 && graph[n][6] != graph[n - 1][2])
        cycle(n - 1, dir * -1, visible);

    //회전 시키기
    if (dir == 1)
        rotate(graph[n].rbegin(), graph[n].rbegin() + 1, graph[n].rend());
    else if (dir == -1)
        rotate(graph[n].begin(), graph[n].begin() + 1, graph[n].end());
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    graph.resize(5);
    for (int i = 1; i <= 4; ++i)
    {
        string str;
        cin >> str;

        for (auto a : str)
            graph[i].push_back(a);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;

        vector<bool> visible(5);
        cycle(p.first, p.second, visible);
    }

    int score = 0;
    for (int i = 1; i <= 4; ++i)
    {
        if (graph[i][0] == '1')
            score += pow(2, i - 1);
    }

    cout << score;
}
