//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<pair<int, int>>> tree;
vector<bool> visible;

int maxSum = 0;
int maxNode = 0;

void dfs(int start, int sum)
{
	if (maxSum < sum)
	{
		maxSum = sum;
		maxNode = start;
	}

	visible[start] = true;

	for (auto a : tree[start])
	{
		if (!visible[a.first])
			dfs(a.first, sum + a.second);
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;
	tree.resize(n + 1);
	visible.resize(n + 1);
	for (int i = 0; i < n; ++i)
	{
		int root;
		cin >> root;

		int node;
		while (cin >> node)
		{
			if (node == -1)
				break;

			int dist;
			cin >> dist;

			tree[root].push_back({ node, dist });
		}
	}

	dfs(1, 0);

	visible.clear();
	visible.resize(n + 1);

	maxSum = 0;
	dfs(maxNode, 0);

	cout << maxSum << endl;
}