#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)

using namespace std;

int n, m;
int answer = int(1e9);
vector<string> graph;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct node {
	int x, y, cnt;
	
	/*
	bool operator<(const node& a) const
	{
		return cnt < a.cnt;
	}*/
};

void bfs()
{
	vector<vector<bool>> visible(n, vector<bool>(m));
	queue<node> pq;
	pq.push({ 0, 0, 1 });

	visible[0][0] = true;

	while (!pq.empty())
	{
		auto cur = pq.front();
		pq.pop();

		if (cur.x == n - 1 && cur.y == m - 1)
		{
			answer = min(answer, cur.cnt);
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visible[nx][ny] || graph[nx][ny] == '0') continue;

			visible[nx][ny] = true;
			pq.push({ nx, ny, cur.cnt + 1 });
		}
	}
}

int main() {
   
	FORMAT;

	cin >> n >> m;

	graph.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> graph[i];

	bfs();

	cout << answer;
}
