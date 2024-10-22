#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)

using namespace std;


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dijkstra(vector<vector<int>> graph, vector<vector<int>>& distance, int start)
{
	priority_queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(-graph[start][start], make_pair(start, start)));

	distance[start][start] = graph[start][start];

	while (!q.empty())
	{
		int dist = -q.top().first;
		pair<int, int> now = q.top().second;
		q.pop();

		if (distance[now.first][now.second] < dist)
			continue;

		//상하좌우 인접한 곳으로 이동하기
		for (int i = 0; i < 4; ++i)
		{
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if (x < 0 || x >= graph.size() || y < 0 || y >= graph.size())
				continue;

			int cost = dist + graph[x][y];

			if (cost < distance[x][y])
			{
				distance[x][y] = cost;
				q.push(make_pair(-cost, make_pair(x, y)));
			}
		}
	}
}

int main() {

	int count = 0;
	while (true)
	{
		count++;

		int n = 0;
		cin >> n;

		if (n == 0)
			return 0;

		vector<vector<int>> graph(n, vector<int>(n));
		vector<vector<int>> distance(n, vector<int>(n, INF));

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int cost = 0;
				cin >> cost;

				graph[i][j] = cost;
			}
		}

		dijkstra(graph, distance, 0);

		int answer = distance[n - 1][n - 1];
		cout << "Problem " << count << ": " << answer << endl;
	}



}