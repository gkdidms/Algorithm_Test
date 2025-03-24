#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int n;
int main()
{
	format;

	cin >> n;
	vector<int> v(200);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<int> dp(201);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j] && dp[i] < dp[j] + 1)
				dp[i]++;
		}
		
		m = max(m, dp[i]);
	}

	cout << n - m;
	
}