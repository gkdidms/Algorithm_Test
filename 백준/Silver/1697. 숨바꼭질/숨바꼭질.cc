#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, k;

int bfs()
{
	vector<int> visible(1000000);
	priority_queue<pair<int, int>> q;
	q.push({ 0, n });

	int dx[2] = { -1, 1 };
	while (!q.empty())
	{
		int time = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (node == k)
		{
			return time;
		}

		for (int i = 0; i < 3; ++i)
		{
			int x;
			if (i == 0)
				x = node * 2;
			else
				x = node + dx[i - 1];

			if (x < 0 || x >= 200001) continue;

			if (!visible[x])
			{
				q.push({ -(time + 1), x });
				visible[x] = true;
			}
			
		}
	}

	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> k;

	cout << bfs();
}