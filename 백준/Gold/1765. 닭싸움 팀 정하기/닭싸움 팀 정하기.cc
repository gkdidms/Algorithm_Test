#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visible;

bool bfs(int start, vector<vector<int>>& f_graph, vector<vector<int>>& e_graph)
{
	if (visible[start])
		return false;

	priority_queue<int> q;
	q.push({ start });

	while (!q.empty())
	{
		int node = q.top();
		q.pop();

		//친구의 친구
		for (auto a : f_graph[node])
		{
			if (!visible[a])
			{
				visible[a] = true;
				q.push(a);
			}
		}

		//내 원수의 원수는 친구이다.
		for (auto b : e_graph[node])
		{
			for (auto notFriend : e_graph[b])
			{
				if (!visible[notFriend])
				{
					visible[notFriend] = true;
					q.push(notFriend);
				}
			}
		}
	}

	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;

	cin >> n >> m;

	vector<vector<int>> f_graph(n + 1);
	vector<vector<int>> e_graph(n + 1);
	visible.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		string str;
		int a, b;

		cin >> str >> a >> b;

		if (str == "F") // 친구
		{
			f_graph[a].push_back(b);
			f_graph[b].push_back(a);
		}
		else if (str == "E") // 원수
		{
			e_graph[a].push_back(b);
			e_graph[b].push_back(a);
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i)
		answer += bfs(i, f_graph, e_graph);

	cout << answer << '\n';
}