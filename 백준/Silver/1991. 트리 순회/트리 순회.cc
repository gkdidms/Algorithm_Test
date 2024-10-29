//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> table;
vector<bool> visible;
int n;

void first(int start)
{
	visible[start] = true;

	if (table[start][0] < 0 && table[start][1] < 0)
	{
		cout << char(start + 65);
		return;
	}

	cout << char(start + 65);
	for (int i = 0; i < table[start].size(); ++i)
	{
		if (table[start][i] < 0 || visible[table[start][i]])
			continue;

		first(table[start][i]);
	}
}

void mid(int start)
{
	visible[start] = true;

	if (table[start][0] < 0 && table[start][1] < 0)
	{
		cout << char(start + 65);
		return;
	}

	if (table[start][0] > 0 && !visible[table[start][0]])
		mid(table[start][0]);

	cout << char(start + 65);

	if (table[start][1] > 0 && !visible[table[start][1]])
		mid(table[start][1]);

}

void end(int start)
{
	visible[start] = true;

	if (table[start][0] < 0 && table[start][1] < 0)
	{
		cout << char(start + 65);
		return;
	}

	if (table[start][0] > 0 && !visible[table[start][0]])
		end(table[start][0]);

	if (table[start][1] > 0 && !visible[table[start][1]])
		end(table[start][1]);

	cout << char(start + 65);
}

void clear_vector()
{
	visible.clear();
	visible.resize(n);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;
	table.resize(n, vector<int>(2));
	visible.resize(n);
	for (int i = 0; i < n; ++i)
	{
		char a, b, c;
		cin >> a >> b >> c;

		table[a - 65][0] = b - 65;
		table[a - 65][1] = c - 65;
	}

	first(0);

	cout << '\n';
	clear_vector();

	mid(0);

	cout << '\n';
	clear_vector();

	end(0);
}