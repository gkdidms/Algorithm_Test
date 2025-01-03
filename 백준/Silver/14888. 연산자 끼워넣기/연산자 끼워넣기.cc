#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> v;
vector<int> op;
int n;

int answer[2] = { INT_MIN, INT_MAX };

void select(int anw, int cnt, vector<int>& visible)
{
    if (cnt - 1 >= n - 1)
    {
        answer[0] = max(anw, answer[0]);
        answer[1] = min(anw, answer[1]);

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (visible[i] >= op[i])
            continue;

        visible[i]++;
        if (i == 0)
        {
            select(anw + v[cnt], cnt + 1, visible);
        }
        else if (i == 1)
        {
            select(anw - v[cnt], cnt + 1, visible);
        }
        else if (i == 2)
        {
            select(anw * v[cnt], cnt + 1, visible);
        }
        else if (i == 3)
        {
            select(anw / v[cnt], cnt + 1, visible);
        }
        visible[i]--;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;
    v.resize(n);
    op.resize(4);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < 4; ++i)
        cin >> op[i];

    vector<int> visible(4);
    select(v[0], 1, visible);

    for (auto a : answer)
        cout << a << '\n';
}
