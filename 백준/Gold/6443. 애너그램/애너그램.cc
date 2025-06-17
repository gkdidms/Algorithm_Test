#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#define FORMAT std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#define ll long long
#define INF int(1e9)
//const ll INF = 1e15;

using namespace std;
vector<string> word;

void make_word(string str, string target, vector<bool>& visible)
{
	if (target.size() == str.size())
	{
		cout << str << '\n';
		return;
	}

	for (int i = 0; i < target.size(); ++i)
	{
		if (visible[i]) continue;
		if (i > 0 && target[i] == target[i - 1] && !visible[i - 1]) continue;

		visible[i] = true;
		str.push_back(target[i]);
		make_word(str, target, visible);
		str.pop_back();
		visible[i] = false;
	}
}

int main() {
	FORMAT;

	int n;
	cin >> n;

	word.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> word[i];
		sort(word[i].begin(), word[i].end());
		vector<bool> visible(word[i].size());
		make_word("", word[i], visible);
	}
}
