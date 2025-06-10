#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long
#define INF int(1e9)

using namespace std;

set<int> s;

int find(string target)
{
	int num = INF;
	for (int i = 0; i < 4; ++i)
	{
		string str = "";
		str += target[i % 4];
		str += target[(i + 1) % 4];
		str += target[(i + 2) % 4];
		str += target[(i + 3) % 4];

		num = min(stoi(str), num);
	}
	
	return num;
}

int main() {
	FORMAT;

	string str = "0000";
	for (int i = 0; i < 4; ++i)
	{
		cin >> str[i];
	}
		

	int num = find(str);
	int answer = 0;
	for (int i = 1111; i <= 9999; ++i)
	{
		string target = to_string(i);
		if (target[0] == '0' || target[1] == '0' || target[2] == '0' || target[3] == '0') continue;

		int t = find(target);

		if (s.find(t) == s.end())
		{
			s.insert(t);
			answer++;
		}

		if (t == num) break;
	}

	cout << answer;
}
