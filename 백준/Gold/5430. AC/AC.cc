#include <cstring>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main()
{
	format;

	int t;

	cin >> t;

	while (t--)
	{
		bool isError = false;
		bool isReverse = false;
		string str, arr;
		int n;

		cin >> str >> n >> arr;

		list<int> v;

		stringstream ss;

		for (auto a : arr)
		{
			if (isdigit(a))
				ss << a;
			else
			{
				if (!ss.str().empty())
				{
					v.push_back(stoi(ss.str()));
					ss.str("");
					ss.clear();
				}
			}
		}
		if (!ss.str().empty())
			v.push_back(stoi(ss.str()));

		for (auto a : str)
		{
			if (a == 'R')
			{
				// 뒤집기
				isReverse = !isReverse;
			}
			else if (a == 'D')
			{
				//배열 첫번째 요소 지우기
				if (v.empty())
				{
					cout << "error" << '\n';
					isError = true;
					break;
				}
				else
				{
					if (isReverse) v.pop_back();
					else v.pop_front();
				}
			}
		}

		if (!isError)
		{
			cout << "[";
			auto iter = v.begin();
			if (isReverse) { iter = v.end(); iter--; }
			for (int i = 0; i < v.size(); ++i)
			{
				cout << (*iter);
				if (i != v.size() - 1) cout << ",";

				if (!isReverse) iter++;
				else {
					if (v.begin() != iter)
						iter--;
				}
			}
			cout << "]" << '\n';
		}

	}

}