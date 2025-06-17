#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long
#define INF int(1e9)
//const ll INF = 1e15;

using namespace std;

int main() {
	FORMAT;

	int n;
	cin >> n;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int m;
			cin >> m;

			graph[i][j] = graph[i - 1][j] + graph[i][j - 1] - graph[i - 1][j-1] + m;
		}
	}

	int pos[4] = { n / 2, n / 2, n / 2 +1, n / 2 +1 }; // 맨위좌표 0, 1/ 오른쪽 아래 좌표 2, 3

	string answer = "";
	int food = 0;
	while (true)
	{
		int now = 0;
		int dir = -1;

		if (pos[0] > 1)
		{
			int up = graph[pos[0] - 1][pos[3]] - graph[pos[0] - 2][pos[3]] - graph[pos[0] - 1][pos[1] - 1] + graph[pos[0] - 2][pos[1] - 1];
			if (up > now)
			{
				now = up;
				dir = 0;
			}
		}

		if (pos[2] < n)
		{
			int down = graph[pos[2] + 1][pos[3]] - graph[pos[2]][pos[3]] - graph[pos[2] + 1][pos[1] - 1] + graph[pos[2]][pos[1] - 1];
			if (down > now)
			{
				now = down;
				dir = 1;
			}
		}

		if (pos[1] > 1)
		{
			int left = graph[pos[2]][pos[1] - 1] - graph[pos[0] - 1][pos[1] - 1] - graph[pos[2]][pos[1] - 2] + graph[pos[0] - 1][pos[1] - 2];
			if (left > now)
			{
				now = left;
				dir = 2;
			}
		}

		if (pos[3] < n)
		{
			int right = graph[pos[2]][pos[3] + 1] - graph[pos[0] - 1][pos[3] + 1] - graph[pos[2]][pos[3]] + graph[pos[0] - 1][pos[3]];
			if (right > now)
			{
				now = right;
				dir = 3;
			}
		}

		if (now <= 0) break;
		food += now;

		if (dir == 0)
		{
			pos[0]--;
			answer += 'U';
		}
		else if (dir == 1)
		{
			pos[2]++;
			answer += 'D';
		}
		else if (dir == 2)
		{
			pos[1]--;
			answer += 'L';
		}
		else if (dir == 3)
		{
			pos[3]++;
			answer += 'R';
		}
	}

	cout << food << '\n' << answer;
}
