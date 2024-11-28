#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<bool> visible;
void dfs(int node)
{
	cout << node << " ";

	for (auto a : graph[node])
	{
		if (!visible[a])
		{
			visible[a] = true;
			dfs(a);
		}
	}
}

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	visible[node] = true;
	cout << node << " ";

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto a : graph[node])
		{
			if (!visible[a])
			{
				visible[a] = true;
				q.push(a);

				cout << a << " ";
			}
		}
	}
}

int main()
{
	format;

	cin >> n >> m >> v;

	graph.resize(n + 1);
	visible.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < graph.size(); ++i)
		sort(graph[i].begin(), graph[i].end());

	visible[v] = true;
	dfs(v);
	cout << '\n';

	visible.clear();
	visible.resize(n + 1);

	bfs(v);

}