#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;

	int maxDay = 0;
	priority_queue < pair<int, int>> q;
	for (int i = 0; i < n; ++i)
	{
		int p, d;
		cin >> p >> d;

		q.push({p,d});
	}

	vector<int> v(10001);
	while (!q.empty())
	{
		int p = q.top().first;
		int d = q.top().second;
		q.pop();

		if (v[d] == 0)
			v[d] = p;
		else
		{
			for (int i = d - 1; i > 0; --i)
			{
				if (v[i] < p)
				{
					v[i] = p;
					break;
				}
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i <= 10000; ++i)
		answer += v[i];

	cout << answer;
}