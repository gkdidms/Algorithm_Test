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

	vector<long long> arraylist(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arraylist[i];
	}

	while (m--)
	{
		sort(arraylist.begin(), arraylist.end());

		long long sum = arraylist[0] + arraylist[1];
		arraylist[0] = sum;
		arraylist[1] = sum;
	}

	long long answer = 0;
	for (int i = 0; i < n; ++i)
		answer += arraylist[i];


	cout << answer;
}