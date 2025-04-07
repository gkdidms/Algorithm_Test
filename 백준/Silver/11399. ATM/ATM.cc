#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int main()
{
	format;

	int n;
	cin >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	vector<int> sum(n);
	sum[0] = v[0];
	int answer = v[0];
	for (int i = 1; i < n; ++i)
	{
		sum[i] = sum[i - 1] + v[i];

		answer += sum[i];
	}

	cout << answer;
}