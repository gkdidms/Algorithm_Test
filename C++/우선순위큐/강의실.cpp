//https://www.acmicpc.net/problem/1374
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

	vector<pair<int, int>> table(n);
	for (int i = 0; i < n; ++i)
	{
		int m = 0, start = 0, end = 0;
		cin >> m >> start >> end;
		table[m - 1] = make_pair(start, end);
	}

	sort(table.begin(), table.end());

	priority_queue<pair<int, int>> q; // 끝나는시간, 시작 시간
	int icount = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (q.size() > 0)
		{
			if (-q.top().first > table[i].first)
			{
				icount++;
			}
			else
				q.pop();
		}
		else
			icount++;

		q.push(make_pair(-table[i].second, table[i].first));
	}

	cout << icount;
}