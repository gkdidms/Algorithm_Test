#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 0x7FFFFFFF

using namespace std;

struct edge {
	int a, b, c;
};

int n, m;
vector<edge> graph;

vector<long long> bellman_ford()
{
	vector<long long> dist(n + 1, INF);
	dist[1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int a = graph[j].a;
			int b = graph[j].b;
			int c = graph[j].c;


			if (dist[a] == INF) continue;

			if (dist[b] > dist[a] + c)
				dist[b] = dist[a] + c;
		}
	}

	return dist;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph.push_back(edge{ a, b, c });
	}
	
	vector<long long> dist = bellman_ford();

	for (int i = 0; i < m; ++i)
	{
		int a = graph[i].a;
		int b = graph[i].b;
		int c = graph[i].c;

		if (dist[a] == INF) continue;

		if (dist[b] > dist[a] + c)
		{
			cout << -1 << "\n";
			return 0;
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (dist[i] == INF) cout << -1 << "\n";
		else  cout << dist[i] << "\n";
	}
		
}