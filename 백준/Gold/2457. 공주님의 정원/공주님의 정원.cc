#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define INT 1000000

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n;
vector<int> v;

int cur = 301;
void roof()
{
	int cnt = 0;
	while (cur < 1201)
	{
		if (cur >= v[cur])
		{
			cout << 0;
			return;
		}

		cur = v[cur];
		cnt++;
		sort(v.begin(), v.begin() + cur + 1);
	}

	cout << cnt;
}

//3월 1일 ~ 11월 31일 
int main()
{
	format;

	cin >> n;
	v.resize(1232);

	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		v[a * 100 + b] = max(v[a * 100 + b], c * 100 + d);
	}

	sort(v.begin(), v.begin() + cur + 1);

	roof();
}
