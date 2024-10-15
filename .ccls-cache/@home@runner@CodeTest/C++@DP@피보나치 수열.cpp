#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int iCnt = 0;
    cin >> iCnt;

    for (int i = 0; i < iCnt; ++i)
    {
        int iInput = 0;
        cin >> iInput;

        if (iInput == 0)
        {
            cout << 1 << " " << 0 << endl;
            continue;
        }
        else if (iInput == 1)
        {
            cout << 0 << " " << 1 << endl;
            continue;
        }

        int n = 0, m = 1;
        for (int i = 2; i <= iInput; ++i)
        {
            int s = n + m;
            n = m;
            m = s;
        }

        cout << n << " " << m << endl;
    }

}

