#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;

	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	vector<int> arr;
	arr.push_back(0);
	for (int i = 0; i < n; ++i)
	{
		if (arr.back() < v[i])
			arr.push_back(v[i]);
		else
		{
			int start = 0;
			int end = arr.size();

			while (start < end)
			{
				int mid = (start + end) / 2;
				if (arr[mid] < v[i])
					start = mid + 1;
				else end = mid;
			}
			
			arr[end] = v[i];
		}
	}

	cout << arr.size() - 1;
}