#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> number;

int bfs(int aa,int bb,int sum)
{
	//int visible[501][501][501];
	vector<vector<int>> visible(2001, vector<int>(2001));

	queue<pair<int, int>> q;
	q.push({ aa, bb });
	visible[aa][bb] = true;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		int c = sum - a - b;
		q.pop();

		if (a == b && b == c)
			return 1;

		int n_x[3] = { a, a, b };
		int n_y[3] = { b, c, c };

		for (int i = 0; i < 3; ++i)
		{
			int na = n_x[i];
			int nb = n_y[i];

			if (na < nb)
				nb -= na, na += na;
			else if (na > nb)
				na -= nb, nb += nb;
			else continue;

			int nc = sum - na - nb;

			int x = min(min(na, nb), nc);
			int y = max(max(na, nb), nc);

			if (visible[x][y] == 0) {
				visible[x][y] = 1;
				q.push({ x,y });
			}
		}
	}

	return 0;
}


int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if ((a + b + c) % 3 != 0)
		cout << 0;
	else
		cout << bfs(a, b, a + b + c);
}