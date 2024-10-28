//https://www.acmicpc.net/problem/7576
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int r, c;
int answer = 0;

void find_count(int start, int x, int y)
{
	if (r == y && c == x)
	{
		//어떤 값을 넣어주어야 할까?
		cout << answer << endl;
		return;
	}
	
	if (r < y + start && r >= y && c < x + start && c >= x)
	{
		find_count(start / 2, x, y);
		find_count(start / 2, x + start / 2, y);
		find_count(start / 2, x, y + start / 2);
		find_count(start / 2, x + start / 2, y + start / 2);
	}
	else
		answer += start * start;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> r >> c;

	find_count((1 << n), 0, 0);
}