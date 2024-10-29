//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> table;
int minResult = 0, maxResult = 1;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;

	table.resize(3);

	vector<int> dp_min(3);
	vector<int> dp_max(3);

	vector<pair<int, int>> copy_table(3);

	for (int i = 1; i < n + 1; ++i)
	{
		cin >> table[0] >> table[1] >> table[2];

		copy_table[0].first = min(dp_min[1] + table[0], dp_min[0] + table[0]);
		copy_table[0].second = max(dp_max[1] + table[0], dp_max[0] + table[0]);

		copy_table[1].first = min(dp_min[2] + table[1], min(dp_min[1] + table[1], dp_min[0] + table[1]));
		copy_table[1].second = max(dp_max[2] + table[1], max(dp_max[1] + table[1], dp_max[0] + table[1]));

		copy_table[2].first = min(dp_min[1] + table[2], dp_min[2] + table[2]);
		copy_table[2].second = max(dp_max[1] + table[2], dp_max[2] + table[2]);

		for (int j = 0; j < 3; ++j)
		{
			dp_min[j] = copy_table[j].first;
			dp_max[j] = copy_table[j].second;
		}
	}

	minResult = min(dp_min[0], min(dp_min[1], dp_min[2]));
	maxResult = max(dp_max[0], max(dp_max[1], dp_max[2]));

	cout << maxResult << " " <<  minResult;
		
}