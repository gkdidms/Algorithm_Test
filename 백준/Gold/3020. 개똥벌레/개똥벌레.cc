#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define INF int(1e9)

using namespace std;

int top[500001];
int bottom[500001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, h;
	cin >> n >> h;

	int num = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		if (i % 2 == 0) bottom[num]++;
		else top[h - num + 1]++;
	}

	for (int i = 1; i <= h; ++i)
	{
		top[i] += top[i - 1];
		bottom[h - i] += bottom[h - i + 1];
	}
	
	int answer = INF;
	int count = 0;

	for (int i = 1; i <= h; ++i)
	{
		if (top[i] + bottom[i] < answer)
		{
			count = 1;
			answer = top[i] + bottom[i];
		}
		else if (top[i] + bottom[i] == answer)
			count++;
	}

	cout << answer << " " << count;

	
}