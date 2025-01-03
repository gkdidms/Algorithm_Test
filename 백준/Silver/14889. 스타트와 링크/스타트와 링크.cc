#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int n;
int min_result = int(1e9);

int select_sum(vector<bool>& start)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!start[i]) continue;

        for (int j = 0; j < n; ++j)
        {
            if (!start[j]) continue;

            if (i != j)
                sum += graph[i][j];
        }
    }

    return sum;
}

void select(int idx, int cnt, vector<bool>& start)
{
    if (cnt >= n / 2)
    {
        int s = 0, l = 0;
        s = select_sum(start);
        vector<bool> link(n);
        for (int i = 0; i < n; ++i)
            if (start[i] == false) link[i] = true;
        l = select_sum(link);

        int anw = abs(s - l);

        if (min_result > anw)
        {
            min_result = anw;
        }

        return;
    }

    for (int i = idx; i < n; ++i)
    {
        start[i] = true;
        select(i + 1, cnt + 1, start);
        start[i] = false;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    cin >> n;

    graph.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    }
    
    vector<bool> visible(n);
    select(0, 0, visible);

    cout << min_result;
}