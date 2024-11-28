#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int n, m;
pair<int, int> anwPos;
vector<vector<int>> graph;
vector<int> visible;
int bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0, anwPos.first });
	visible[anwPos.first] = true;

	while (!q.empty())
	{
		int cnt = q.front().first;
		int node = q.front().second;
		q.pop();

		if (node == anwPos.second)
			return cnt;

		for (auto a : graph[node])
		{
			if (!visible[a])
			{
				visible[a] = true;
				q.push({ cnt + 1, a });
			}
		}
	}
	
	return -1;
}

int main()
{
	format;

	cin >> n;
	cin >> anwPos.first >> anwPos.second;

	cin >> m;

	graph.resize(n + 1);
	visible.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs();
}