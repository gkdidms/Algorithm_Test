#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define INF 2000000001

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int start = 0;
	int end = n - 1;

	long long minResult = INF;
	pair<int, int> answer = {0 , 0 };
	while (start < end)
	{
		long long anw = abs(v[start] + v[end]);
		minResult = min(minResult, anw);

		if (minResult == anw)
		{
			answer = { v[start], v[end] };
		}
			
		if (abs(v[start]) > abs(v[end]))
			start++;
		else
			end--;
	}

	if (answer.first < answer.second)
		cout << answer.first << " " << answer.second;

}