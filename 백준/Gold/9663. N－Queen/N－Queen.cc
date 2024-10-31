//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int answer = 0;
vector<vector<int>> visible;

bool is_Queen(int row, int col)
{
	//같은 열에 있는가?
	for (int i = 0; i < col; ++i)
		if (visible[row][i])
			return false;

	//왼쪽 대각선에 위치하는가
	int i = row, j = col;
	while (i >= 0 && j >= 0)
	{
		if (visible[i][j])
			return false;

		--i, --j;
	}

	//오른쪽 대각선에 위치하는가
	i = row, j = col;
	while (i < n && j >= 0)
	{
		if (visible[i][j])
			return false;

		++i, --j;
	}


	return true;
}

void dfs(int y)
{
	if (y == n)
	{
		++answer;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (is_Queen(i, y))
		{
			visible[i][y] = true;
			dfs(y + 1);
			visible[i][y] = false;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;

	visible.resize(n, vector<int>(n));
	dfs(0);

	cout << answer;
}