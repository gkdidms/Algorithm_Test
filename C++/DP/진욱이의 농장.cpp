//https://www.acmicpc.net/problem/1460
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;

int answer = 0;

int search(int target1, int target2)
{
	vector<vector<int>> table(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (graph[i][j] == target1 || graph[i][j] == target2)
				table[i][j] = 1;
		}
	}

	int map = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (table[i][j] == 0)
				continue;
			table[i][j] = min(table[i - 1][j], min(table[i - 1][j - 1], table[i][j - 1])) + 1;
			map = max(map, table[i][j]);
		}
	}

	return map * map;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n, vector<int>(n));
	for (int i = 0; i < m; ++i)
	{
		int x, y, l, e;
		cin >> x >> y >> l >> e;
		for (int j = x; j < x + l; ++j)
		{
			for (int k = y; k < y + l; ++k)
			{
				graph[j][k] = e;
			}
		}
	}

	for (int i = 1; i < 8; ++i)
	{
		for (int j = 1; j < 8; ++j)
			answer = max(answer, search(i, j));
	}

	cout << answer << endl;

}