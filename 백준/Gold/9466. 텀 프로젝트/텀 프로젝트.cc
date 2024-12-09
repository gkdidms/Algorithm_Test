#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INF int(1e9)
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

vector<int> v;
vector<bool> visible;
vector<bool> finished;
int answer = 0;

void dfs(int node)
{
	visible[node] = true;
	int next = v[node];

	if (!visible[next])
		dfs(next);
	else if (!finished[next])
	{
		for (int i = next; i != node; i = v[i])
		{
			answer++;
		}
		answer++;
	}

	finished[node] = true;

}

int main()
{
	format;

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		answer = 0;
		v.clear();
		v.resize(n + 1);
		visible.clear();
		visible.resize(n + 1);
		finished.clear();
		finished.resize(n + 1);

		for (int i = 1; i <= n; ++i)
			cin >> v[i];

		for (int i = 1; i <= n; ++i)
		{
			if (!visible[i])
				dfs(i);
		}

		answer = n - answer;

		cout << answer << '\n';
	}
}