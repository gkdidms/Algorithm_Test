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

	int n, m, answer = 0;
	cin >> n >> m;
	priority_queue<int> q;
	vector<int> v(n);

	//콘센트 세팅
	for (int i = 0; i < m; ++i)
		q.push(0);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < n; ++i)
	{
		int x = -q.top() + v[i];
		q.pop();
		q.push(-x);

		answer = max(x, answer);
	}

	cout << answer;
}