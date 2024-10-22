//https://www.acmicpc.net/problem/9084
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t = 0;
	cin >> t;

	for (int _ = 0; _ < t; ++_)
	{
		//������ ����
		int n = 0;
		cin >> n;

		//������ �� �ݾ� �������� 
		vector<int> coin(n + 1);

		for (int i = 1; i < n + 1; ++i)
		{
			cin >> coin[i];
		}

		//�ݾ�
		int m = 0;
		cin >> m;

		vector<int> dp(m + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = coin[i]; j <= m; ++j)
			{
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}

		cout << dp[m] << endl;
	}
}