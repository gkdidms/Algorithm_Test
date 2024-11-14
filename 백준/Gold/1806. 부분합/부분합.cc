#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define INF int(1e9)

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, s;
	int minRange = INF;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		if (i == 0) v[i] = num;
		else v[i] = v[i - 1] + num;
	}

	int start = 0, end = 0;
	while (end < n)
	{
		if (start == 0)
		{
			while (end < n && v[end] < s)
			{
				end++;
			}
			
			if (v[end] >= s)
			{
				start++;
				minRange = min(minRange, end + 1);
			}
		}
		else
		{
			if (v[end] - v[start - 1] >= s)
			{
				minRange = min(minRange, end - start + 1);
				start++;
			}
			else
				end++;
		}
	}

	if (minRange == INF) cout << 0 << '\n';
	else cout << minRange << '\n';
}