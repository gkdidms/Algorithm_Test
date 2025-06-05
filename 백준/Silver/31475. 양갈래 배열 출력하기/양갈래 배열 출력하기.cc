#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)

using namespace std;

struct node {
	int x, y, num;
	char dir;
};

int n, m;
vector<vector<int>> answer;
queue<node> q;

void move(node& cur)
{
	if (cur.dir == 'D')
	{
		//아래로 증가
		if (cur.x + 1 >= n || answer[cur.x + 1][cur.y] != 0)
		{
			if (cur.y - 1 >= 0 && answer[cur.x][cur.y - 1] == 0)
			{
				answer[cur.x][cur.y - 1] = cur.num + 1;
				q.push({ cur.x, cur.y - 1, cur.num + 1, 'L' });
			}

			if (cur.y + 1 < m && answer[cur.x][cur.y + 1] == 0)
			{
				answer[cur.x][cur.y + 1] = cur.num + 1;
				q.push({ cur.x, cur.y + 1, cur.num + 1, 'R' });
			}

		}
		else
		{
			answer[cur.x + 1][cur.y] = cur.num + 1;
			q.push({ cur.x + 1, cur.y, cur.num + 1, cur.dir });
		}
	}
	else if (cur.dir == 'U')
	{
		//위로 증가
		if (cur.x - 1 < 0 || answer[cur.x - 1][cur.y] != 0)
		{
			if (cur.y - 1 >= 0 && answer[cur.x][cur.y - 1] == 0)
			{
				answer[cur.x][cur.y - 1] = cur.num + 1;
				q.push({ cur.x, cur.y - 1, cur.num + 1, 'L' });
			}
			if (cur.y + 1 < m && answer[cur.x][cur.y + 1] == 0)
			{
				answer[cur.x][cur.y + 1] = cur.num + 1;
				q.push({ cur.x , cur.y + 1, cur.num + 1, 'R' });
			}
		}
		else
		{
			answer[cur.x - 1][cur.y] = cur.num + 1;
			q.push({ cur.x - 1, cur.y, cur.num + 1, cur.dir });
		}
	}
	else if (cur.dir == 'L')
	{
		//왼쪽으로 증가
		if (cur.y - 1 < 0 || answer[cur.x][cur.y - 1] != 0)
		{
			if (cur.x - 1 >= 0 && answer[cur.x - 1][cur.y] == 0)
			{
				answer[cur.x - 1][cur.y] = cur.num + 1;
				q.push({ cur.x - 1, cur.y, cur.num + 1, 'U' });
			}
			if (cur.x + 1 < n && answer[cur.x + 1][cur.y] == 0)
			{
				answer[cur.x + 1][cur.y] = cur.num + 1;
				q.push({ cur.x + 1, cur.y, cur.num + 1, 'D' });
			}
		}
		else
		{
			answer[cur.x][cur.y - 1] = cur.num + 1;
			q.push({ cur.x, cur.y - 1, cur.num + 1, cur.dir });
		}
	}
	else if (cur.dir == 'R')
	{
		//오른쪽으로 증가
		if (cur.y + 1 >= m || answer[cur.x][cur.y + 1] != 0)
		{
			if (cur.x - 1 >= 0 && answer[cur.x - 1][cur.y] == 0)
			{
				answer[cur.x - 1][cur.y] = cur.num + 1;
				q.push({ cur.x - 1, cur.y, cur.num + 1, 'U' });
			}
			if (cur.x + 1 < n && answer[cur.x + 1][cur.y] == 0)
			{
				answer[cur.x + 1][cur.y] = cur.num + 1;
				q.push({ cur.x + 1, cur.y, cur.num + 1, 'D' });
			}
		}
		else
		{
			answer[cur.x][cur.y + 1] = cur.num + 1;
			q.push({ cur.x, cur.y + 1, cur.num + 1, cur.dir });
		}
	}
}

int main() {

	FORMAT;


	cin >> n >> m;

	char type;
	cin >> type;

	answer.resize(n, vector<int>(m));

	if (type == 'U')
	{
		//위에서 시작
		q.push({ 0, (m - 1) / 2, 1, 'D'});
		answer[0][(m - 1) / 2] = 1;
	}
	else if (type == 'D')
	{
		//아래
		q.push({ n - 1, (m - 1) / 2, 1, 'U' });
		answer[n - 1][(m - 1) / 2] = 1;
	}
	else if (type == 'L')
	{
		//왼
		q.push({ (n - 1) / 2, 0, 1, 'R' });
		answer[(n - 1) / 2][0] = 1;
	}
	else if (type == 'R')
	{
		//오른쪽
		q.push({ (n - 1) / 2, m - 1, 1, 'L' });
		answer[(n - 1) / 2][m - 1] = 1;
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		move(cur);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << answer[i][j] << " ";
		}
		cout << '\n';
	}
}
