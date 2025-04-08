#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int a, b;

struct node {
	long long n;
	long long cnt;
};

long long bfs()
{
	queue<node> q; // 합
	q.push({ a, 0 });

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.n == b)
		{
			return cur.cnt + 1;
		}

		for (int i = 0; i < 2; ++i)
		{
			node next = cur;

			if (i == 0) next.n *= 2;
			else next.n = next.n * 10 + 1;
			
			if (next.n > b) continue;

			q.push({ next.n, next.cnt + 1 });
		}
	}

	return -1;
}

int main()
{
	format;

	cin >> a >> b;

	long long answer = bfs();

	cout << answer;
}