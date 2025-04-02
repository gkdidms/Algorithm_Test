#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

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

	stack<int> s;
	vector<string> answer;
	vector<bool> visible(n + 1);
	visible[0] = true;
	int i = 1;
	int idx = 0;

	s.push(1);
	answer.push_back("+");
	while (!s.empty())
	{
		if (idx > v.size()) break;
		else
		{
			if (i >= n && s.top() < v[idx]) break;
		}

		if (s.top() == v[idx])
		{
			while (idx < v.size() && !s.empty() && s.top() == v[idx])
			{
				visible[v[idx]] = true;
				idx++;
				s.pop();
				answer.push_back("-");
			}
		}
		else if (s.top() > v[idx])
		{
			while (idx < v.size() && !s.empty() && s.top() >= v[idx])
			{
				if (s.top() == v[idx])
				{
					visible[v[idx]] = true;
					idx++;
				}
				s.pop();
				answer.push_back("-");
			}
		}

		if (i < n)
		{
			s.push(++i);
			answer.push_back("+");
		}

		
	}

	for (bool visit : visible)
	{
		if (visit == false)
		{
			cout << "NO" << '\n';

			return 0;
		}
	}

	for (auto i : answer)
		cout << i << '\n';


}