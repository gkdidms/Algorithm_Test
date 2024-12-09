#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	int n;
	cin >> n;

	vector<vector<int>> v(n + 1);
	
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
	}

	priority_queue<int> q;
	int answer = 0;
	for (int i = n; i >= 1; --i)
	{
		for (auto a : v[i])
			q.push(a);
		
		if (!q.empty())
		{
			answer += q.top();
			q.pop();
		}
	}
	
	cout << answer;
}