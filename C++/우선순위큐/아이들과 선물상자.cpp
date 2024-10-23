//https://www.acmicpc.net/problem/23757
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

	int n = 0, m = 0; // 선물상자의 개수, 아이들의 수
	cin >> n >> m;

	priority_queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		int gift = 0;
		cin >> gift;

		q.push(gift);
	}

	vector<int> mq;
	for (int i = 0; i < m; ++i)
	{
		int size = 0;
		cin >> size;
		mq.push_back(size);
	}

	int icnt = 0;
	while (!q.empty())
	{
		if (icnt >= m)
			break;

		int gift = q.top();
		q.pop();

		if (gift - mq[icnt] < 0)
			break;
		else
		{
			gift -= mq[icnt];
			icnt += 1;
		}

		if (gift != 0)
			q.push(gift);
	}

	std::cout << (icnt == m ? 1 : 0) << endl;
}