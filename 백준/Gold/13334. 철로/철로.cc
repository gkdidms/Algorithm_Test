#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INT 1000000

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	format;

	int n, l;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; ++i)
	{
		int h, o;
		cin >> h >> o;

		if (h > o)
			v.push_back({ o, h });
		else
			v.push_back({ h, o });
	}

	cin >> l; //포함되어야 할 거리

	sort(v.begin(), v.end(), cmp);

	priority_queue<int> q;

	int answer = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		int h = v[i].first;
		int o = v[i].second;

		if (o - h <= l) q.push(-h);
		else continue;

		while (!q.empty())
		{
			if (-q.top() < o - l) q.pop();
			else
			{
				answer = max(answer, (int)q.size());
				break;
			}
		}
	}

	cout << answer << endl;
}
