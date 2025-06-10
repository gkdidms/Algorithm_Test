#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long
#define INF int(1e9)

using namespace std;

int main() {
	FORMAT;

	int n, m;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cin >> m;

	int first = INF, second = INF;
	int first_idx = 0, second_idx = 0;

	for (int i = 0; i < n; ++i)
	{
		if (v[i] < first)
		{
			first = v[i];
			first_idx = i;
		}
	}
	
	for (int i = 1; i < n; ++i)
	{
		if (v[i] < second)
		{
			second = v[i];
			second_idx = i;
		}
	}

	if (m < second)
	{
		cout << "0";
		return 0;
	}

	m -= second;

	string answer = "";
	answer.push_back('0' + second_idx);
	while (m >= first)
	{
		answer.push_back('0' + first_idx);
		m -= first;
	}

	int idx = 0;
	for (int i = 0; i < answer.size(); ++i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			idx = answer[i] - '0';

			if (m >= v[j] - v[idx])
			{
				m -= (v[j] - v[idx]);
				answer[i] = '0' + j;
				break;
			}
		}
	}

	cout << answer;
}
