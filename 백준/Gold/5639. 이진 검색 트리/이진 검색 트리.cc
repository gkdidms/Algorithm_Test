//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> table;
int root = 0;
void dfs(int start, int end)
{
	if (start >= end)
		return;
	
	if (start == end - 1)
	{
		cout << table[start] << endl;
		return;
	}
	
	int idx = start + 1;
	while (idx < end)
	{
		//왼쪽 판별
		if (table[idx] > table[start])
			break;

		++idx;
	}

	//왼
	dfs(start + 1, idx);
	//오
	dfs(idx, end);

	//중간
	cout << table[start] << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n = 0;
	while (cin >> n)
	{
		table.push_back(n);
	}

	dfs(0, table.size());
}