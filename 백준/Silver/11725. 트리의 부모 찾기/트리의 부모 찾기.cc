//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<int>> tree;
vector<int> answer;

void bfs()
{
	priority_queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int node = q.top();
		q.pop();

		for (auto a : tree[node])
		{
			if (answer[a] == 0)
			{
				answer[a] = node;
				q.push(a);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;
	tree.resize(n + 1);
	answer.resize(n + 1);

	for (int i = 0; i < n - 1; ++i)
	{
		int r, c;
		cin >> r >> c;

		tree[r].push_back(c);
		tree[c].push_back(r);
	}

	bfs();

	for (int i = 2; i <= n; ++i)
		cout << answer[i] << '\n';
}