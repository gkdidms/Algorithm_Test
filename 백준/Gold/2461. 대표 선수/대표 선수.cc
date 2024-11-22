#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF int(1e9)

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;

	cin >> n >> m;
	
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}

		sort(v[i].begin(), v[i].end());
	}

	

	priority_queue<int, vector<int>, greater<int>> q;

	vector<int> idx(n);
	
	while (true)
	{
		int MAX = 0;
		int MIN = INF;

		int MAX_IDX = 0;
		int MIN_IDX = 0;

		int answer[3];

		for (int i = 0; i < n; ++i)
		{
			MAX = max(MAX, v[i][idx[i]]);
			MIN = min(MIN, v[i][idx[i]]);

			if (MIN == v[i][idx[i]]) MIN_IDX = i;
		}

		q.push(MAX - MIN);
		idx[MIN_IDX]++;

		bool isExit = false;
		for (int i = 0; i < n; ++i)
			if (idx[i] == m)
				isExit = true;

		if (isExit) break;
	}

	cout << q.top();
}