//https://www.acmicpc.net/problem/7576
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<bool> table;

void Backtracking(int count, vector<int>& list)
{
	if (count == 0)
	{
		if (!is_sorted(list.begin(), list.end()))
			return;

		for (auto num : list)
			cout << num << " ";

		cout << endl;
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		auto find_num = find(list.begin(), list.end(), i);
		if (find_num == list.end())
		{
			list.push_back(i);
			Backtracking(count - 1, list);
			list.erase(list.end() - 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;
	vector<int> answer;
	Backtracking(m, answer);
}