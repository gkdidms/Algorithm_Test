//https://www.acmicpc.net/problem/19598
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int answer;
vector<vector<int>> Table;
vector<vector<int>> CopyTable;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//바이러스 확산 ( 0 -> 2)
void bfs()
{
	vector<vector<int>> Table2 = CopyTable;

	priority_queue<pair<int, int>> q;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (Table2[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty())
	{
		pair<int, int> pos = q.top();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = pos.first + dx[i];
			int y = pos.second + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;

			if (Table2[x][y] == 0)
			{
				Table2[x][y] = 2;
				q.push(make_pair(x, y));
			}
		}
	}

	int iCount = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (Table2[i][j] == 0)
				iCount++;
		}
	}

	answer = max(answer, iCount);
}

void Wall(int iCount)
{
	if (iCount >= 3)
	{
		bfs();
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (CopyTable[i][j] == 0)
			{
				CopyTable[i][j] = 1;
				Wall(iCount + 1);
				CopyTable[i][j] = 0;
			}
			
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;

	Table.resize(n, vector<int>(m));
	CopyTable.resize(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> Table[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (Table[i][j] == 0)
			{
				CopyTable = Table;
				CopyTable[i][j] = 1;
				Wall(1);
			}
		}
	}

	cout << answer << endl;
}