#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	string str, bomb;
	stack<char> s;

	cin >> str >> bomb;

	int n = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		s.push(str[i]);
		if (str[i] == bomb[bomb.size() - 1] && s.size() >= bomb.size())
		{
			//같다면
			string temp;
			for (int j = 0; j < bomb.size(); ++j)
			{
				temp.push_back(s.top());
				s.pop();
			}

			reverse(temp.begin(), temp.end());

			if (temp != bomb)
			{
				for (auto a : temp)
					s.push(a);
			}
		}
	}

	if (s.empty()) cout << "FRULA";
	else
	{
		string answer;
		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			answer.push_back(s.top());
			s.pop();
		}

		reverse(answer.begin(), answer.end());
		cout << answer;
	}
}