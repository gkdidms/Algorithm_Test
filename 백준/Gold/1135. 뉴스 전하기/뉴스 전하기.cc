#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<int>> tree;
vector<int> dp;

int dfs(int curr)
{
	vector<int> v;
	int ref = 0;
	int cnt = tree[curr].size() - 1;
	for (auto a : tree[curr])
		v.push_back(dfs(a));

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
		ref = max(ref, v[i] + cnt--);

	return ref + 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;
	tree.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (num == -1)
			continue;

		tree[num].push_back(i);
	}

	int answer = dfs(0);

	cout << answer - 1;
}