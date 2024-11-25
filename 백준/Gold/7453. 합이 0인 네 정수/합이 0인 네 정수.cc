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

	int n;
	cin >> n;

	int A[4001], B[4001], C[4001], D[4001];

	for (int i = 0; i < n; ++i)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	vector<int> sums;
	
	for (int i = 0; i < n; ++i)
	{
		int value = 0;
		for (int j = 0; j < n; ++j)
		{
			value = A[i] + B[j];
			sums.push_back(value);
		}
	}

	sort(sums.begin(), sums.end());
	long long answer = 0;
	for (int i = 0; i < n; ++i)
	{
		int value = 0;
		for (int j = 0; j < n; ++j)
		{
			value = C[i] + D[j];
			answer += upper_bound(sums.begin(), sums.end(), -value) - lower_bound(sums.begin(), sums.end(), -value);
		}	
	}

	cout << answer;
}