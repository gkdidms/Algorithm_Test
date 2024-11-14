#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n,m;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		if (i == 0)
			v[i] = num;
		else
			v[i] = v[i - 1] + num;
	}

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (a == 1)
			cout << v[b - 1] << endl;
		else
			cout << (v[b - 1] - v[a - 2]) << '\n';
	}

}