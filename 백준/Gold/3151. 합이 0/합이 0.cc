#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INT 1000000

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	long long answer = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			long long cnt = v[i] + v[j];

			int idx1 = lower_bound(v.begin() + j + 1, v.end(), -cnt) - v.begin();
			int idx2 = upper_bound(v.begin() + j + 1, v.end(), -cnt) - v.begin();

			answer += idx2 - idx1;
		}
	}

	cout << answer;

}
