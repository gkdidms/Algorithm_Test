//https://www.acmicpc.net/problem/2910

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n = 0, c = 0;
    cin >> n >> c;

    unordered_map<int, int> table;
    vector<int> input;

    for (int i = 0; i < n; ++i)
    {
        int m = 0;
        cin >> m;

        if (table.find(m) == table.end())
        {
            table.insert({ m, 1 });
            input.push_back(m);
        }

        else
            table[m] += 1;
    }

    vector<pair<int, int>> table2(table.begin(), table.end());

    sort(table2.begin(), table2.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        if (a.second > b.second)
            return true;
        if (a.second == b.second && find(input.begin(), input.end(), a.first) < find(input.begin(), input.end(), b.first))
            return true;

        return false;
        });

    for (auto answer : table2)
    {
        for (int _ = 0; _ < answer.second; ++_)
            cout << answer.first << " ";
    }
}