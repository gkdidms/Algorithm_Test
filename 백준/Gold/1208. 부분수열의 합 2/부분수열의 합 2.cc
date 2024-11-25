#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, s;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<int> sums;
	int mid = n / 2;

	for (int i = 0; i < (1 << mid); ++i)
	{
		int value = 0;
		for (int j = 0; j < mid; ++j)
		{
			if (i & (1 << j)) value += v[j];
		}

		sums.push_back(value);
	}

	sort(sums.begin(), sums.end());

	long long answer = 0;

	for (int i = 0; i < (1 << (n - mid)); ++i)
	{
		int value = 0;
		for (int j = 0; j < (n - mid); ++j)
		{
			if (i & (1 << j)) value += v[j + mid];
		}

		answer += upper_bound(sums.begin(), sums.end(), s - value) - lower_bound(sums.begin(), sums.end(), s - value);
	}

	if (s == 0) answer--;

	cout << answer;
}