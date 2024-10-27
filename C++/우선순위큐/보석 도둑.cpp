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

		mv.push_back({ m, v}); // 무게, 가격
	}

	sort(mv.begin(), mv.end()); // 무게 순으로 정렬한다

	vector<int> bag(k);
	for (int i = 0; i < k; ++i)
		cin >> bag[i];

	sort(bag.begin(), bag.end());
	
	priority_queue<int> q; // 금액만 저장
	long long answer = 0;

	int idx = 0;
	for (int i = 0; i < k; ++i)
	{
		while (idx < n && bag[i] >= mv[idx].first) // 넣을 수 있는 애들 중에서 가격이 제일 큰 보석의 값을 저장...
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