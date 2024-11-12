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

	int n;
	cin >> n;

	priority_queue<int> max_q;
	priority_queue<int> min_q;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		if (i == 0)
			max_q.push(num);
		else if (i == 1)
		{
			if (max_q.top() < num)
			{
				min_q.push(-num);
			}
			else
			{
				min_q.push(-max_q.top());
				max_q.pop();
				max_q.push(num);
			}
		}
		else
		{
			max_q.push(num);

			if (max_q.top() > -min_q.top())
			{
				max_q.pop();
				min_q.push(-num);
				if (min_q.size() > max_q.size())
				{
					max_q.push(-min_q.top());
					min_q.pop();
				}
			}
			if (max_q.size() - min_q.size() > 1)
			{
				min_q.push(-max_q.top());
				max_q.pop();
			}
		}

		cout << max_q.top() << "\n";
	}

}