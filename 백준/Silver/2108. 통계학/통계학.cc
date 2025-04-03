#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <cmath>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int main()
{
	format;


	int n;
	cin >> n;

	deque<int> v(n);

	int answer[4] = {};
	map <int, int> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		m[v[i]]++;
		answer[0] += v[i];
	}

	//산술 평균
	int arg = round(double(answer[0]) / n);
	answer[0] = arg;


	//중앙값
	sort(v.begin(), v.end());
	answer[1] = v[n / 2];

	//범위
	answer[3] = (*v.rbegin()) - v.front();

	//최빈값 : 여러 개 있을 때는 최빈값 중 두 번째로 작은 수
	int maxInt = 0;
	vector<int> modes;
	for (auto a : m)
	{
		if (maxInt < a.second)
		{
			maxInt = a.second;
			modes = { a.first };
		}
		else if (maxInt == a.second)
		{
			modes.push_back(a.first);
		}
	}

	if (modes.size() == 1) answer[2] = modes[0];
	else
	{
		sort(modes.begin(), modes.end());

		answer[2] = modes[1];
	}

	for (auto a : answer)
		cout << a << '\n';
}