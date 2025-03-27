#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int n;
int main()
{
	format;

	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int end = 0;
	long long answer = 0;

	vector<bool> visible(n + 1);

	for (int start = 0; start < n; ++start)
	{
		while (end < n)
		{
			if (visible[v[end]]) break;

			visible[v[end]] = true;
			end++;
		}

		answer += (end - start);
		visible[v[start]] = false;
	}

	cout << answer;
}