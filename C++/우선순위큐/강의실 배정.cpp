//https://www.acmicpc.net/problem/11000
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n = 0;
	cin >> n;

	vector<pair<int, int>> table;
	for (int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;

		table.push_back(make_pair(start, end));
	}
	
	sort(table.begin(), table.end());

	priority_queue<int> q;
	q.push(-table[0].second);
	for (int i = 1; i < n; ++i)
	{
		if (-q.top() <= table[i].first)
			q.pop();
		
		q.push(-table[i].second);
	}

	cout << q.size();
}