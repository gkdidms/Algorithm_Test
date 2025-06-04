#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define INF int(1e9)
using namespace std;


int main() {

	FORMAT;

	int n, k;
	cin >> n >> k;

	vector<vector<bool>> holes(n, vector<bool>(21));
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;

		for (int j = 0; j < m; ++j)
		{
			int h;
			cin >> h;

			holes[i][h] = true;
		}
	}

	vector<vector<int>> minT(n + 1, vector<int>(21, INF));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	pq.push({ 0, {0, 1} }); // t 사용 횟수, 현재 나무, 현재 나무 높이
	minT[0][1] = 0;

	while (!pq.empty())
	{
		int curT = pq.top().first;
		int curTree = pq.top().second.first;
		int curH = pq.top().second.second;
		pq.pop();

		if (curTree == n)
		{
			cout << curT;
			return 0;
		}

		if (curTree >= n) continue;

		int nextTree = curTree + 1;

		if (holes[curTree][curH])
		{
			if (minT[nextTree][curH] > curT)
			{
				minT[nextTree][curH] = curT;
				pq.push({ curT, {nextTree, curH} });
			}
		}

		if (curH + 1 <= 20 && holes[curTree][curH + 1])
		{
			if (minT[nextTree][curH + 1] > curT)
			{
				minT[nextTree][curH + 1] = curT;
				pq.push({ curT, {nextTree, curH + 1} });
			}
		}

		int h = (curH * 2) > 20 ? 20 : curH * 2;
		if (holes[curTree][h])
		{
			if (minT[nextTree][h] > curT)
			{
				minT[nextTree][h] = curT;
				pq.push({ curT, {nextTree, h} });
			}
		}

		if (curH - 1 >= 1 && holes[curTree][curH - 1])
		{
			if (minT[nextTree][curH - 1] > curT)
			{
				minT[nextTree][curH - 1] = curT;
				pq.push({ curT, {nextTree, curH - 1} });
			}
		}

		if (curT < k)
		{
			for (int h = 1; h <= 20; ++h)
			{
				if (holes[curTree][h] && minT[nextTree][h] > curT + 1)
				{
					minT[nextTree][h] = curT + 1;
					pq.push({ curT + 1, {nextTree, h} });
				}
			}
		}
	}

	cout << -1;

}
