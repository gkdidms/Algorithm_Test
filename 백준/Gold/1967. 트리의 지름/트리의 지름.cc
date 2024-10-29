//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF int(1e9)
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<bool> visible;
int answer = 0;
int maxSum = -1, maxNode = 0;
void dfs(int start, int sum)
{
	if (maxSum < sum)
	{
		maxSum = sum;
		maxNode = start;
	}

	visible[start] = true;
	for (auto a : graph[start])
	{
		if (visible[a.first])
			continue;

		dfs(a.first, sum + a.second);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;

	graph.resize(n + 1);
	visible.resize(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	dfs(1, 0);
	visible.clear();
	visible.resize(n + 1);
	maxSum = -1;
	dfs(maxNode, 0);

	cout << maxSum << '\n';
}