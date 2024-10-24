//https://www.acmicpc.net/problem/2667
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<int>> table;

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y)
{
	if (table[x][y] > 1 || table[x][y] == 0)
		return 0;

	priority_queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	int answer = 0;
	while (!q.empty())
	{
		pair<int, int> pos = q.top();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = pos.first + dx[i];
			int y = pos.second + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= n)
				continue;

			if (table[x][y] == 1)
			{
				table[x][y] += 1;
				q.push(make_pair(x, y));
				answer++;
			}
		}
	}

	if (answer == 0)
		answer++;

	return answer;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;

	table.resize(n);

	for (int i = 0; i < n; ++i)
	{
		string m;
		cin >> m;

		for (auto a : m)
		{
			table[i].push_back(int(a - '0'));
		}
	}

	vector<int> answer;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int iCount = 0;
			iCount = bfs(i, j);
			
			if (iCount != 0) answer.push_back(iCount);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (auto a : answer)
		cout << a << endl;
}