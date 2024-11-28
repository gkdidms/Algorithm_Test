#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int main()
{
	format;

	int n, m;

	cin >> n >> m;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		v[i] = v[i - 1] + v[i];
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << v[b] - v[a - 1] << '\n';
	}

}