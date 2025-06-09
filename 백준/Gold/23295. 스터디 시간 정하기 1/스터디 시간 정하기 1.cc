#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long

using namespace std;


int main() {
	FORMAT;

	int n, t;
	cin >> n >> t;

	vector<ll> sum(100'002);
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;

		for (int j = 0; j < k; ++j)
		{
			int s,e;
			cin >> s >> e;

			sum[s] += 1;
			sum[e] -= 1;
		}
	}
	
	for (int i = 1; i < 100'001; ++i)
	{
		sum[i] += sum[i - 1];
	}

	ll window = 0;
	for (int i = 0; i < t; ++i)
	{
		window += sum[i];
	}

	pair<int, int> answer = {0, t};
	ll max_p = window;
	for (int start = 1; start + t - 1 < 100'001; ++start)
	{
		window -= sum[start - 1];
		window += sum[start + t - 1];

		if (window > max_p)
		{
			max_p = window;
			answer = { start, start + t };
		}
	}

	cout << answer.first << " " << answer.second;

}
