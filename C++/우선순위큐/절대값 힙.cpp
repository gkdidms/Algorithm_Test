//https://www.acmicpc.net/problem/11286
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n = 0;
	cin >> n;

	priority_queue<int, vector<int>, comp> q;
	for (int i = 0; i < n; ++i)
	{
		int m = 0;
		cin >> m;

		if (m == 0)
		{
			//0이라면 배열에서 가장 작은 수 출력하기
			//배열이 비어있다면
			if (q.empty())
			{
				cout << 0 << endl;
				continue;
			}

			//비어있지 않다면?
			cout << q.top() << endl;
			q.pop();
		}
		else
		{
			q.push(m);
		}
			
	}
}