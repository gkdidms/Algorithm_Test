//https://www.acmicpc.net/problem/1504
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int n, e;
int v1, v2;

vector<vector<pair<int, int>>> graph;

void dijkstra(int start, vector<int>& dist)
{
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	dist[start] = 0;

	while (!q.empty())
	{
		int distance = -q.top().first;
		int node = q.top().second;
		q.pop();

		for (auto a : graph[node])
		{
			int cost = distance + a.second;

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

	cin >> n >> e;
	graph.resize(n + 1);

	for (int i = 0; i < e; ++i)
	{
		int a, b, c;

		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a,c });
	}

	cin >> v1 >> v2;

	vector<int> dist1(n+1, INF);

	dijkstra(1, dist1);
	
	int answer1, answer2, answer3;

	//중간지점
	vector<int> dist2_1(n + 1, INF);
	vector<int> dist2_2(n + 1, INF);

	dijkstra(v1, dist2_1);
	int temp1 = dist2_1[v2];
	int temp_n = dist2_1[n];

	dijkstra(v2, dist2_2);
	int temp2 = dist2_2[v1];
	int temp2_n = dist2_2[n];

	int answer = min(dist1[v1] + temp1 + temp2_n, dist1[v2] + temp2 + temp_n);

	if (answer > INF || answer < 0)
		cout << -1 << endl;
	else
		cout << answer << endl;

}