#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;

	map<string, priority_queue<int>> maps;

	long long answer = 0;

	for (int i = 0; i < n; ++i)
	{
		int a, num; // 숫자와
		string name; // 상인 이름
		cin >> a >> name >> num;

		if (a == 1)
		{
			priority_queue<int> q;
			int b;
			
			while (num--)
			{
				cin >> b;
				maps[name].push(b);
			}
		}
		else if (a == 2)
		{
			while (num--)
			{
				if (maps[name].empty()) break;

				answer += maps[name].top();
				maps[name].pop();
			}
		}
	}

	cout << answer;
}