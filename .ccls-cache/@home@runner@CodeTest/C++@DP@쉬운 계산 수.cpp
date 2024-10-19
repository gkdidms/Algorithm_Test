//https://www.acmicpc.net/problem/10844 (다시풀기)

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define MOD 1000000000

using namespace std;

int main() {
    int iCnt = 0;
    cin >> iCnt;

    vector<vector<int>> dp(iCnt + 1, vector<int>(10));

    for (int i = 1; i < 10; ++i)
        dp[1][i] = 1;

    for (int i = 2; i < iCnt + 1; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j > 0 && j < 9)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; ++i)
        answer = (answer + dp[iCnt][i]) % MOD;

    cout << answer << endl;
}