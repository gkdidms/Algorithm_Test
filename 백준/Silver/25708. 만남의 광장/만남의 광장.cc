#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long
#define INF int(1e9)
//const ll INF = 1e15;

using namespace std;

// 조합 구하기 (nC2)
vector<pair<int, int>> get_combinations(int n) {
	vector<pair<int, int>> comb;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			comb.push_back({ i, j });
		}
	}
	return comb;
}

int main() {
	FORMAT;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> road(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> road[i][j];
		}
	}

	vector<int> road_row(n); // 가로합
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			road_row[i] += road[i][j];
	}

	vector<int> road_col(m); // 세로합
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			road_col[j] += road[i][j];
		}
	}

	vector<pair<int, int>> row_comb = get_combinations(n);
	vector<pair<int, int>> col_comb = get_combinations(m);

	int answer = -INF;

	for (auto row : row_comb)
	{
		for (auto col : col_comb)
		{
			int d = road[row.first][col.first] + road[row.first][col.second] + road[row.second][col.first] + road[row.second][col.second];

			int value = road_row[row.first] + road_row[row.second] + road_col[col.first] + road_col[col.second] - d + ((row.second - row.first - 1) * (col.second - col.first - 1));

			answer = max(answer, value);
		}
	}

	cout << answer;
}
