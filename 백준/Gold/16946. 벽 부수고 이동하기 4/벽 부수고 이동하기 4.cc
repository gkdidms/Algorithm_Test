#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

using namespace std;

int n, m;
int nbr = 1;
vector<vector<int>> v, numbering, answer;
vector<int> zero_size;

void dfs(int x, int y)
{
	priority_queue<pair<int, int>> q;
	q.push({ x,y });
	int cnt = 1;
	numbering[x][y] = nbr;
	while (!q.empty())
	{
		int x = q.top().first;
		int y = q.top().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			
			if (numbering[nx][ny] == 0 && v[nx][ny] == 0)
			{
				numbering[nx][ny] = nbr;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
	zero_size.push_back(cnt);
	nbr++;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;
	v.resize(n);
	numbering.resize(n, vector<int>(m));
	answer.resize(n, vector<int>(m));
	

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (auto a : str)
		{
			v[i].push_back(a - '0');
		}
	}

	zero_size.push_back(0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			if (numbering[i][j] == 0 && v[i][j] == 0)
				dfs(i, j);
	}

	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 0) continue;

			answer[i][j] = 1;
			for (int k = 0; k < 4; ++k)
			{
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 0 || x >= n || y < 0 || y >= m || numbering[x][y] == 0)
					continue;

				s.insert(numbering[x][y]);
			}

			for (auto a : s)
				answer[i][j] += zero_size[a];

			s.clear();
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << answer[i][j] % 10;

		cout << "\n";
	}

}