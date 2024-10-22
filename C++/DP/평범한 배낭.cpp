#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 0, k = 0;
	cin >> n >> k;

	vector<pair<int, int>> bag(n + 1);
	for (int _ = 1; _ < n + 1; ++_)
	{
		int w = 0, v = 0; // 무게와 가치
		cin >> w >> v;

		bag[_] = make_pair(w, v);
	}

	vector<vector<int>> table(n + 1, vector<int>(k + 1));

	
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < k + 1; ++j)
		{
			if (bag[i].first > j)
				table[i][j] = table[i - 1][j];
			else
				table[i][j] = max(table[i - 1][j], bag[i].second + table[i - 1][j - bag[i].first]);
		}
	}

	cout << table[n][k] << endl;

}