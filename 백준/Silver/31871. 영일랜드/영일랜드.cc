#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long
using namespace std;

int n, m;
vector<vector<ll>> graph;
vector<bool> visible;
ll answer = -1;

void backtracking(int idx, ll sum, int cnt)
{
	if (cnt == n + 1 && idx == 0)
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i <= n; ++i)
	{
		if (graph[idx][i] == 0 || visible[i]) continue;

		visible[i] = true;
		backtracking(i, sum + graph[idx][i], cnt + 1);
		visible[i] = false;
	}
}

int main() {

	FORMAT;

	cin >> n >> m;

	graph.resize(n + 1, vector<ll>(n + 1));

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;

		graph[a][b] = max(graph[a][b], c);
	}

	visible.resize(n + 1);
	backtracking(0, 0, 0);
	
	cout << answer;
}
