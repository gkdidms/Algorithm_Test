//https://www.acmicpc.net/problem/2075
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

	int n = 0;
	cin >> n;

	priority_queue<int> q;
	for (int i = 0; i < n * n; ++i)
	{
		int m = 0;
		cin >> m;

		//n번째로 큰 수를 넣어라
		if (q.size() >= n)
		{
			if (-q.top() < m)
			{
				q.pop();
				q.push(-m);
			}
		}
		else
			q.push(-m);
	}

	cout << -q.top() << endl;
}