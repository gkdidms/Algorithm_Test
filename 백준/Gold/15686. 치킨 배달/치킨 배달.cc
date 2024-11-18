#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

#define INF int(1e9);

using namespace std;

struct house {
	int r, l;
};

struct chicken {
	int r, l;
	bool visible;
};

vector<house> houses;
vector<chicken> chickens;

int n, m;
int answer = INF;

void ChickenDistance()
{
	int chickenDst = 0;
	for (int i = 0; i < houses.size(); ++i)
	{
		int minDst = INF;
		for (int j = 0; j < chickens.size(); ++j)
		{
			if (chickens[j].visible)
			{
				int dst = abs(houses[i].r - chickens[j].r) + abs(houses[i].l - chickens[j].l);
				minDst = min(dst, minDst);
			}
		}

		chickenDst += minDst;
	}

	answer = min(answer, chickenDst);
}

void dfs(int index, int count)
{
	if (count == m)
	{
		ChickenDistance();
		return;
	}
		
	for (int i = index; i < chickens.size(); ++i)
	{
		if (!chickens[i].visible)
		{
			chickens[i].visible = true;
			dfs(i, count + 1);
			chickens[i].visible = false;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;

			if (num == 1)
				houses.push_back({ i, j });
			else if (num == 2)
				chickens.push_back({ i, j, false });
		}
	}

	dfs(0, 0);

	cout << answer;
}