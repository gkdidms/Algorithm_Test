#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
using namespace std;

int n, m;
vector<int> v;

void dfs(int cnt, vector<bool>& visible, vector<int>& nums)
{
	if (cnt == m)
	{
		for (auto num : nums) cout << num << " ";

		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visible[i] == true) continue;

		visible[i] = true;
		nums.push_back(v[i]);
		dfs(cnt + 1, visible, nums);
		visible[i] = false;
		nums.pop_back();
	}
}

int main()
{
	format;

	cin >> n >> m;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; ++i)
	{
		vector<bool> list(n);
		vector<int> nums;
		nums.push_back(v[i]);
		list[i] = true;
		dfs(1, list, nums);
	}
}