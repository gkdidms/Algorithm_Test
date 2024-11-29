#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;
int f, s, g, u, d;

vector<bool> visible;

int bfs()
{
	priority_queue<pair<int, int>> q;
	q.push({ 0, s });
	visible[s] = true;

	while (!q.empty())
	{
		int cnt = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (node == g)
			return cnt;

		for (int i = 0; i < 2; ++i)
		{
			int x;
			if (i == 0) x = node + u;
			else if (i == 1) x = node - d;

			if (x > f || x < 1 || visible[x]) continue;

			visible[x] = true;
			q.push({ -(cnt + 1), x });
		}
	}

	return -1;
}

int main()
{
	format;
	
	cin >> f >> s >> g >> u >> d;

	visible.resize(f + 1);

	int answer = bfs();

	if (answer == -1)
		cout << "use the stairs";
	else
		cout << answer;

}