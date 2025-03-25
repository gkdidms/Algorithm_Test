#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        multiset<int> s;

        for (int i = 0; i < k; ++i)
        {
            int n;
            char str;

            cin >> str >> n;

            if (str == 'I')
            {
                s.insert(n);
            }
            else if (str == 'D')
            {
                if (s.empty()) continue;

                if (n == -1) s.erase(s.begin());
                else s.erase(prev(s.end()));
            }
        }

        if (s.empty()) cout << "EMPTY" << '\n';
        else
        {
            cout << *(prev(s.end())) << " " << *(s.begin()) << '\n';
        }
    }
}
