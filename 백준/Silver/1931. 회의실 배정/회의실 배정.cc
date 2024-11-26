#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		v.push_back({ b,a });
	}

	sort(v.begin(), v.end());

	int endTime = 0;
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		if (endTime <= v[i].second)
		{
			answer++;
			endTime = v[i].first;
		}
	}

	cout << answer;
}