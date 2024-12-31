#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int n, w, l;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> w >> l;
    queue<int> q1; // 기다리는 트럭
    deque<pair<int ,int>> q2; // 다리를 건너는 트럭

    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;

        q1.push(m);
    }

    int time = 0;

    while (!q1.empty() || !q2.empty())
    {
        for (int i = 0; i < q2.size(); ++i)
            q2[i].second--;

        if (!q2.empty() && q2.front().second == 0) q2.pop_front();

        int weight = 0;
        for (auto a : q2) weight += a.first;

        if (!q1.empty() && q1.front() + weight <= l && q2.size() < w)
        {
            q2.push_back({ q1.front(), w});
            q1.pop();
        }

        time++;
    }

    cout << time;
}