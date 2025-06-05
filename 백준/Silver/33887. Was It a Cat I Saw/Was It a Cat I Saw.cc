#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_set>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)

using namespace std;

int answer;

unordered_set<int> visible;

void cmp(int n, int cnt)
{
	if (cnt >= answer) return;
	if (visible.count(n)) return;
	visible.insert(n);

	string temp1;
	bool isStart = false;

	for (int i = 31; i >= 0; --i)
	{
		if (n & (1 << i))
		{
			isStart = true;
		}
		if (isStart)
		{
			temp1 += (n & (1 << i)) ? '1' : '0';
		}
	}

	string temp2 = temp1;
	reverse(temp2.begin(), temp2.end());

	if (temp1 == temp2)
	{
		answer = min(answer, cnt);
		return;
	}
	
	cmp(n + 1, cnt + 1);
	if (n - 1 > 1)
		cmp(n - 1, cnt + 1);
}

int main() {

	FORMAT;

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		answer = int(1e9);

		visible.clear();
		cmp(n, 0);
		cout << answer << '\n';

	}
}
