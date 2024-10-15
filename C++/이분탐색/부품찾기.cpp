#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<int> list_n(n);
    for (int i = 0; i < n; i++)
        cin >> list_n[i];

    cin >> m;
    vector<int> list_m(m);
    for (int i = 0; i < m; i++)
        cin >> list_m[i];

    sort(list_n.begin(), list_n.end());

    for (int i = 0; i < m; i++)
    {
        int start = 0;
        int end = n - 1;
        int mid = 0;
        int result = 0;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (list_n[mid] == list_m[i])
            {
                cout << "yes ";
                result = 1;
                break;
            }
            else
            {
                if (list_n[mid] < list_m[i])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        if (result == 0)
            cout << "no ";
    }
}
