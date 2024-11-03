//https://www.acmicpc.net/problem/1504
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visible;

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1 };


int answer = 0;

void dfs(int x, int y, int count)
{
	answer = max(answer, count);

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (!visible[graph[nx][ny]])
		{
			visible[graph[nx][ny]] = true;
			dfs(nx, ny, count + 1);
			visible[graph[nx][ny]] = false;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n);
	visible.resize(91); // 대문자 알파벳 아스키코드값 (60~90)

	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;

		for (auto a : temp)
		{
			graph[i].push_back(a);
		}
	}
	visible[graph[0][0]] = true;
	dfs(0, 0, 1);
	cout << answer << endl;
}