//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)

using namespace std;


int n, k;
int cnt = 0;
int minResult = INF;

int dx[2] = { -1, 1 };

vector<int> visible;

void bfs()
{
	priority_queue<pair<int, int>> q;
	q.push({0, n});

	while (!q.empty())
	{
		int dist = -q.top().first;
		int x = q.top().second;
		q.pop();

		visible[x] = true;
		
		if (x == k)
		{
			if (minResult == INF || minResult == dist)
			{
				minResult = dist;
				cnt++;
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			int nx = 0;
			if (i == 0)
				nx = x + 1;
			else if (i == 1)
				nx = x - 1;
			else if (i == 2)
				nx = x * 2;

			if (nx < 0 || nx > 100001)
				continue;

			if (!visible[nx])
			{
				q.push({ -(dist + 1), nx });
			}
			
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	visible.resize(100001 * 2);

	cin >> n >> k;

	if (n == k)
	{
		minResult = 0;
		cnt = 1;
	}
	else
	{
		bfs();
	}
	

	cout << minResult << '\n';
	cout << cnt << '\n';
	
}