#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int main()
{
	format;

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;

		cin >> n >> m;

		queue<pair<int, int>> q;

		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			q.push({ temp, i });
		}

		int cnt = 0;
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();

			int q_size = q.size();

			queue<pair<int, int>> copy = q;
			bool isPrint = true;
			for (int j = 0; j < q_size; ++j)
			{
				if (copy.front().first > cur.first)
				{
					isPrint = false;
					break;
				}
				else
				{
					copy.pop();
				}
			}

			if (isPrint == false)
			{
				q.push(cur);
			}
			else
			{
				cnt++;
				if (m == cur.second)
				{
					cout << cnt << endl;
					break;
				}
			}
		}
	}
}