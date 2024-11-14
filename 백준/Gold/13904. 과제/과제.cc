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

	priority_queue<pair<int, int>> q;
	int maxInt = 0;
	for (int i = 0; i < n; ++i)
	{
		int d, w;
		cin >> d >> w;

		q.push({ w, d });
		maxInt = max(maxInt, d);
	}

	vector<bool> visible(maxInt + 1);
	int answer = 0;
	while (!q.empty())
	{
		int day = q.top().second;
		int w = q.top().first;
		q.pop();

		for (int i = day; i > 0; --i)
		{
			if (visible[i])
				continue;

			visible[i] = true;
			answer += w;
			break;
		}
	}

	cout << answer;
}