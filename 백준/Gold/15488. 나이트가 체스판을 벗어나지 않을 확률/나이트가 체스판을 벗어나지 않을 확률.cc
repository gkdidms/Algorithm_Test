#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long

using namespace std;
//(x + 1, y + 2), (x + 2, y + 1), (x + 2, y - 1), (x + 1, y - 2), (x - 1, y - 2), (x - 2, y - 1), (x - 2, y + 1), (x - 1, y + 2)

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int n, k;
pair<int, int> pos;

vector<vector<vector<double>>> table(51, vector<vector<double>>(51, vector<double>(51, -1)));

double dp(int x, int y, int cnt)
{
	if (x <= 0 || x > n || y <= 0 || y > n) return 0;
	if (table[x][y][cnt] != -1) return table[x][y][cnt];
	if (cnt == 0) return table[x][y][cnt] = 1;

	double& ret = table[x][y][cnt];
	ret = 0;

	for (int i = 0; i < 8; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		ret += dp(nx, ny, cnt - 1);
	}

	return ret = ret / 8;
}


int main() {
	FORMAT;

	cin >> n >> pos.first >> pos.second >> k;

	if (k == 0)
	{
		cout << 1;
		return 0;
	}

	double answer = dp(pos.first, pos.second, k);
	
	cout << fixed;
	cout.precision(10);
	cout << answer;
}
