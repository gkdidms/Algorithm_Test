//https://www.acmicpc.net/problem/1043
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

	int n, m;

	cin >> n >> m;

	priority_queue<long long> q;
	for (int i = 0; i < n; ++i)
	{
		long long num;
		cin >> num;

		q.push(-num);
	}

	while (m--)
	{
		long long firstNum = -q.top();
		q.pop();

		long long secondNum = -q.top();
		q.pop();

		long long sum = firstNum + secondNum;
		q.push(-sum);
		q.push(-sum);
	}

	long long answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer += -q.top();
		q.pop();
	}


	cout << answer;
}