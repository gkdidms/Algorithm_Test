#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1};

int n ;
vector<vector<int>> graph;
int curX, curY;

int ShakeSize = 2;
int ate = 0;

int bfs()
{
	vector<vector<int>> visible(n, vector<int>(n));

	int dist = 0;

	queue<pair<int, int>> q; // 상어의 이동 경로
	q.push({curY, curX});
	visible[curY][curX] = 1;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 상어가 먹을 수 있는 물고기 위치
	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (visible[y][x] == dist)
			break;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (visible[ny][nx]) continue;

			if (graph[ny][nx] == 0 || graph[ny][nx] == ShakeSize)
			{
				q.push({ ny, nx });
				visible[ny][nx] = visible[y][x] + 1;
			}
			else if (graph[ny][nx] < ShakeSize)
			{
				//먹을 수 있을 때
				if (!dist) ate++;
				visible[ny][nx] = visible[y][x] + 1;
				dist = visible[ny][nx];
				pq.push({ ny, nx });
			}
		}
	}

	if (pq.empty()) return 0;
	
	curY = pq.top().first;
	curX = pq.top().second;

	graph[curY][curX] = 0;

	if (ate == ShakeSize)
	{
		ShakeSize++;
		ate = 0;
	}

	return visible[curY][curX] - 1; // 이동 횟수
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;

	graph.resize(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 9)
			{
				curY = i;
				curX = j;
				graph[i][j] = 0;
			}
				
		}
	}

	int answer = 0;
	while (true)
	{
		int mov = bfs();
		answer += mov;
		if (!mov)
			break;
	}

	cout << answer;
	
}