//https://www.acmicpc.net/problem/1043
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int c;

vector<int> table;
vector<vector<int>> graph;
vector<int> parent;

int find_node(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = find_node(parent[x]);
}

void union_node(int x, int y)
{
	int a = find_node(x);
	int b = find_node(y);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}



int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> m;
	parent.resize(n + 1);

	//진실을 아는 사람들
	cin >> c;
	table.resize(c);
	for (int i = 0; i < c; ++i)
	{
		cin >> table[i];
	}

	//파티마다 오는 사람들
	graph.resize(m);
	for (int i = 0; i < m; ++i)
	{
		int a;
		cin >> a;

		for (int j = 0; j < a; ++j)
		{
			int b;
			cin >> b;
			
			graph[i].push_back(b);
		}
	}

	//진실을 아는 사람이 없을 경우 0
	if (table.empty())
	{
		cout << m << endl;
		return 0;
	}

	//부모 테이블상에서 부모를 자기 자신으로 초기화
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	//진실을 아는 사람은 0
	for (auto a : table)
		parent[a] = 0;
	
	//union 연산을 각각 수행
	for (int i = 0; i < m; ++i)
	{
		if (graph[i].size() >= 2)
		{
			for (int j = 0; j < graph[i].size(); ++j)
			{
				for (int k = 0; k < graph[i].size(); ++k)
				{
					if (j == k)
						continue;
					union_node(graph[i][j], graph[i][k]);
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		parent[i] = find_node(i);


	
	int answer = 0;
	for (int i = 0; i < m; ++i)
	{
		bool isAnswer = false;
		for (auto a : graph[i])
		{
			if (parent[a] == 0)
			{
				isAnswer = true;
				break;
			}
		}

		if (!isAnswer) ++answer;
	}

	cout << answer << endl;
}