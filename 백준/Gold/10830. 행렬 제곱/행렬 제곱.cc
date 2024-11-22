#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define INF int(1e9)

using namespace std;

int n;
long long b;
vector<vector<long long>> graph;

void compute_matrix(vector<vector<long long>>& v, vector<vector<long long>>& v2)
{
	vector<vector<long long>> v3(v);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int sum = 0;
			for (int k = 0; k < n; ++k)
			{
				sum += v[i][k] * v2[k][j];
			}

			v3[i][j] = sum % 1000;
		}
	}

	v = v3;
}

vector<vector<long long>> dfs(vector<vector<long long>> rc, long long count)
{
	if (count == 1)
		return rc;

	vector<vector<long long>> ans = dfs(rc, count / 2);

	if (count % 2 == 0)
	{
		compute_matrix(ans, ans);
	}
	else
	{
		compute_matrix(ans, ans);
		compute_matrix(ans, rc);
	}

	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> b;
	graph.resize(n, vector<long long>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}

	vector<vector<long long>> answer = dfs(graph, b);
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << answer[i][j] % 1000 << " ";
		}
		cout << '\n';
	}
}