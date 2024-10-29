//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int n, e;
int start;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra()
{
	priority_queue<pair<int, int>> q;
	q.push({0, start});
	dist[start] = 0;

	while (!q.empty())
	{
		int distance = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (distance > dist[node])
			continue;

		for (auto i : graph[node])
		{
			int cost = distance + i.second;
			if (cost < dist[i.first])
			{
				dist[i.first] = cost;
				q.push({ -cost, i.first });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> e;
	cin >> start;
	graph.resize(n + 1);
	dist.resize(n + 1, INF);
	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
	}

	dijkstra();

	for (int i = 1; i <= n; ++i)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
		


}