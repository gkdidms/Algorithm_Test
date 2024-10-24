//https://www.acmicpc.net/problem/10026
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<string>> table;
vector<vector<bool>> visible;
vector<vector<bool>> rgbVisible;

int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bfs_normal(int x, int y)
{
	if (visible[x][y])
		return false;

	priority_queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		pair<int, int> pos = q.top();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (!visible[nx][ny])
			{
				//¿œπ›
				if (table[nx][ny] == table[x][y])
				{
					visible[nx][ny] = true;
					q.push(make_pair(nx, ny)); 
				}
			}
			
		}
		
	}

	return true;
}

bool bfs_RGB(int x, int y)
{
	if (rgbVisible[x][y])
		return false;

	priority_queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		pair<int, int> pos = q.top();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (!rgbVisible[nx][ny])
			{
				if ((table[x][y] == "R" || table[x][y] == "G") && table[nx][ny] != "B")
				{
					rgbVisible[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				else if (table[nx][ny] == table[x][y])
				{
					rgbVisible[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return true;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	cin >> n;
	table.resize(n);
	visible.resize(n, vector<bool>(n));
	rgbVisible.resize(n, vector<bool>(n));

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (auto a : s)
		{
			string m(1, a);
			table[i].push_back(m);
		}
			
	}

	vector<pair<bool, bool>> answer;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			pair<bool, bool> count;
			count.first = bfs_normal(i, j);
			count.second = bfs_RGB(i, j);

			answer.push_back(count);
		}
	}

	int a = 0, b = 0;
	for (auto i : answer)
	{
		if (i.first) 
			++a;
		if (i.second) 
			++b;
	}

	cout << a << " " << b;
}