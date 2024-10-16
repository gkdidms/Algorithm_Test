#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int iCnt = 0;
    cin >> iCnt;

    vector<int> list_n(iCnt);

    for (int i = 0; i < iCnt; ++i)
    {
        cin >> list_n[i];
    }

    cin >> iCnt;

    sort(list_n.begin(), list_n.end());

    vector<int> list_m(iCnt);

    for (int i = 0; i < iCnt; ++i)
    {
        cin >> list_m[i];
    }

    for (auto m : list_m)
    {
        auto lower = lower_bound(list_n.begin(), list_n.end(), m);
        auto upper = upper_bound(list_n.begin(), list_n.end(), m);// m 보다 큰 값의 인덱스를 반환한다.

        int start = 0;
        int end = 0;
        if (lower != list_n.end() && (*lower) == m)
        {
            start = distance(list_n.begin(), lower); // distance : 반복자가 벡터의 처음부터 얼마나 떨어져있는지에 대한 거리를 구한다.
            end = distance(list_n.begin(), upper);
        }

        cout << end - start << " ";
    }
}