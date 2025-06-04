#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)

using namespace std;


int main() {

	FORMAT;

	int n, s, m;
	cin >> n >> s >> m;

	vector<int> v(m);
	for (int i = 0; i < m; ++i)
		cin >> v[i];

	int cnt = 0;
	int t = 0;

	while (1)
	{
		for (int i = 0; i < m; ++i)
		{
			if (t % v[i] == 0)
			{
				cnt++;
				if (cnt >= n - s)
				{
					cout << i + 1;
					return 0;
				}
			}
		}
		t++;
	}
}
