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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<int> entry(32001);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		entry[b]++;
	}

	priority_queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (entry[i] == 0) q.push(-i);
	}

	while (!q.empty())
	{
		int cur = -q.top();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];
			entry[next]--;

			if (entry[next] == 0) q.push(-next);
		}
	}
}