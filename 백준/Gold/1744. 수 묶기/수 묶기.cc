#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INT 1000000

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	int n;
	cin >> n;

	vector<int> p; // 양수
	vector<int> m;

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;

		if (a > 0) p.push_back(a);
		else m.push_back(a);
	}

	sort(p.begin(), p.end(), greater<>()); // 내림차순
	sort(m.begin(), m.end()); // 오름차순

	int answer = 0;

	if (p.size() % 2 != 0) answer += p[p.size() - 1]; // 양수가 홀수개일 경우 마지막 요소를 더해준다.
	if (p.size() > 0)
	{
		for (int i = 0; i < p.size() - 1; i += 2)
		{
			if (p[i + 1] == 1) answer += p[i] + p[i + 1];
			else if (p[i + 1] > 0) answer += p[i] * p[i + 1];
		}
	}

	if (m.size() % 2 != 0) answer += m[m.size() - 1];
	if (m.size() > 0)
	{
		for (int i = 0; i < m.size() - 1; i += 2)
			answer += m[i] * m[i + 1];
	}


	cout << answer;
	
}
