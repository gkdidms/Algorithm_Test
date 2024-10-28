//https://www.acmicpc.net/problem/11724
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int answer;

vector<vector<int>> graph;
vector<bool> visible;

bool bfs(int start)
{
	if (visible[start])
		return false;

	priority_queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int node = q.top();
		q.pop();

		for (auto a: graph[node])
		{
			if (!visible[a])
			{
				visible[a] = true;
				q.push(a);
			}
		}
	}

	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n + 1);
	visible.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (bfs(i))
			++answer;
	}

	cout << answer << endl;
}