#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

char charlist[5] = { 'a', 'e', 'i', 'o', 'u'};
vector<char> words;
map<string, int> answer;

int l, c;

bool check_vowels(string str)
{
	int v_count = 0;
	int j_count = 0;

	for (auto a : str)
	{
		if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') v_count++;
		else j_count++;
	}

	if (v_count >= 1 && j_count >= 2)
		return true;
	else
		return false;
}

void dfs(string word, int num, int count)
{
	if (count == l)
	{
		if (!check_vowels(word)) return;

		if (answer[word] < 1)
		{
			sort(word.begin(), word.end());
			cout << word << '\n';
		}
			

		answer[word]++;
			
		return;
	}

	for (int i = num + 1; i <= c; ++i)
	{
		dfs(word + words[i], i, count + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> l >> c;

	words.resize(c + 1);

	for (int i = 1; i <= c; ++i)
	{
		char str;
		cin >> str;

		words[i] = str;
	}

	sort(words.begin(), words.end());

	dfs("", 0, 0);
}