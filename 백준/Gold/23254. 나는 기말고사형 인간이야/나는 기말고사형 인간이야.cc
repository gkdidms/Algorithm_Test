#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return min(100 - a.first, a.second) < min(100 - b.first, b.second);
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v(m);
	for (int i = 0; i < m; ++i) cin >> v[i].first;
	for (int j = 0; j < m; ++j) cin >> v[j].second;

	int time = n * 24;

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
	for (auto a : v)
	{
		q.push(a);
	}
	
	int answer = 0;
	for (int i = 0; i < time; ++i)
	{
		if (q.empty())
			break;

		auto score = q.top();
		q.pop();

		score.first = min(100, score.first + score.second);

		if (score.first == 100)
		{
			answer += 100;
			continue;
		}
		q.push(score);
	}

	while (!q.empty())
	{
		answer += q.top().first;
		q.pop();
	}


	cout << answer << '\n';

}