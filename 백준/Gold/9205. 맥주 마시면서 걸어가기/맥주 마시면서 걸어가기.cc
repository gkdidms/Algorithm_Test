#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int dx[4] = { -50, 50, 0, 0 };
int dy[4] = { 0, 0, -50, 50 };

int n;

bool bfs(pair<int, int>& startPos, vector<pair<int, int>>& marts, pair<int, int>& festivelPos)
{
	vector<bool> visible(n);
	queue< pair<int, int>> q;
	q.push(startPos);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (abs(festivelPos.first - x) + abs(festivelPos.second - y) <= 1000)
			return true;

		for (int i = 0; i < n; ++i)
		{
			if (visible[i])
				continue;

			int dist = abs(marts[i].first - x) + abs(marts[i].second - y);
			if (dist <= 1000)
			{
				visible[i] = true;
				q.push({ marts[i].first, marts[i].second});
			}
		}
	}

	return false;
}

int main()
{
	format;

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;

		pair<int, int> startPos;
		cin >> startPos.first >> startPos.second;

		vector<pair<int, int>> mart;
		for (int i = 0; i < n; ++i)
		{
			pair<int, int> martPos;
			cin >> martPos.first >> martPos.second;
			mart.push_back(martPos);
		}

		pair<int, int> festivelPos;
		cin >> festivelPos.first >> festivelPos.second;

		if (bfs(startPos, mart, festivelPos))
			cout << "happy" << '\n';
		else 
			cout << "sad" << '\n';
	}
}