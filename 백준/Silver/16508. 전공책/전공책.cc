#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long

using namespace std;

vector<pair<int, string>> books;
string str;
int n;
int answer = int(1e9);

vector<bool> checking_book;

bool checking_s(vector<bool>& s)
{
	for (auto a : s)
		if (a == false) return false;

	return true;
}

void check(int cost, vector<bool>& checking_str)
{
	if (checking_s(checking_str))
	{
		answer = min(answer, cost);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (checking_book[i]) continue;
		vector<bool> copy = checking_str;
		
		bool isCheck = false;
		string book = books[i].second;
		for (int j = 0; j < book.size(); ++j)
		{
			for (int k = 0; k < str.size(); ++k)
			{
				if (copy[k]) continue;
				if (book[j] == str[k])
				{
					copy[k] = true;
					isCheck = true;
					break;
				}
			}
		}

		if (isCheck)
		{
			checking_book[i] = true;
			check(cost + books[i].first, copy);
			checking_book[i] = false;
		}
	}
}

int main() {
	FORMAT;

	cin >> str >> n;

	books.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> books[i].first >> books[i].second;
	}

	vector<bool> checking_str(str.size());
	checking_book.resize(n);
	check(0, checking_str);

	if (answer == int(1e9))
		cout << -1;
	else
		cout << answer;
}
