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

	int n, answer = 0;
	cin >> n;
	priority_queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		q.push(-temp);
	}

	while (q.size() != 1)
	{
		int sour = -q.top();
		q.pop();

		int dust = -q.top();
		q.pop();

		int sum = sour + dust;
		q.push(-sum);

		answer += sum;
	}

	cout << answer << endl;


}