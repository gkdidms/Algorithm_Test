//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int n, m, x;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& dist, int start)
{
	priority_queue<pair<int, int>>q;
	q.push({ 0, start });

	dist[start] = 0;

	while (!q.empty())
	{
		int d = -q.top().first;
		int node = q.top().second;
		q.pop();

		for (auto a : graph[node])
		{
			int cost = d + a.second;

			if (dist[a.first] > cost)
			{
				dist[a.first] = cost;
				q.push({ -cost, a.first });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);


	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> startGraph(n + 1);
	vector<vector<pair<int, int>>> endGraph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		startGraph[a].push_back({ b, c });
		endGraph[b].push_back({ a, c });
	}

	vector<int> startDist(n + 1, INF);
	vector<int> endDist(n + 1, INF);
	dijkstra(endGraph, startDist, x);
	dijkstra(startGraph, endDist, x);

	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i == x) continue;

		answer = max(answer, startDist[i] + endDist[i]);
	}

	cout << answer << endl;
}