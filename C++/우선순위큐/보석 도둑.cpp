//https://www.acmicpc.net/problem/1202
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

vector<vector<int>> graph;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> k;

	vector<pair<int, int>> mv;
	for (int i = 0; i < n; ++i)
	{
		int m, v;

		cin >> m >> v;

		mv.push_back({ m, v}); // ����, ����
	}

	sort(mv.begin(), mv.end()); // ���� ������ �����Ѵ�

	vector<int> bag(k);
	for (int i = 0; i < k; ++i)
		cin >> bag[i];

	sort(bag.begin(), bag.end());
	
	priority_queue<int> q; // �ݾ׸� ����
	long long answer = 0;

	int idx = 0;
	for (int i = 0; i < k; ++i)
	{
		while (idx < n && bag[i] >= mv[idx].first) // ���� �� �ִ� �ֵ� �߿��� ������ ���� ū ������ ���� ����...
		{
			q.push(mv[idx].second);
			idx++;
		}

		if (!q.empty())
		{
			answer += q.top();
			q.pop();
		}
	}

	cout << answer << endl;
}