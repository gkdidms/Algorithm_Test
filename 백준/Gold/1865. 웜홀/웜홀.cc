//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)

using namespace std;

int n;
int answer = 0;

struct edge {
	int s, e, t;
};

bool bellman_ford(int n, vector<edge>& graph)
{
	vector<int> dist(n + 1, INF);

	int s, e, t;
	dist[1] = 0;

	//모든 노드에 대한 거리 구하기
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < graph.size(); ++j)
		{
			s = graph[j].s;
			e = graph[j].e;
			t = graph[j].t;

			if (dist[e] > dist[s] + t)
				dist[e] = dist[s] + t;
		}
	}

	for (int j = 0; j < graph.size(); ++j)
	{
		s = graph[j].s;
		e = graph[j].e;
		t = graph[j].t;

		if (dist[e] > dist[s] + t)
			return true;
	}

	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int tc;
	cin >> tc;

	while (tc--)
	{
		
		int n, m, w;
		cin >> n >> m >> w;

		vector<edge> graph;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			graph.push_back({ a, b, c });
			graph.push_back({ b, a, c });
		}

		for (int i = 0; i < w; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			graph.push_back({ a, b, -c });
		}

		if (bellman_ford(n, graph))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

	}


}