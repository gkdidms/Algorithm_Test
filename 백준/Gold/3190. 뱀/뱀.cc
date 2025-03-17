#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <list>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

struct apple {
	int x, y;
	bool isErase = false;
};

struct turn {
	int time;
	char dir;
};

int n, k, L;
vector<apple> apples;
vector<turn> turns;
list<pair<int, int>> s; //뱀의 몸통 위치

bool bump(pair<int, int> target)
{
	for (auto a : s)
	{
		if (target.first == a.first && target.second == a.second) return true;
	}

	return false;
}

bool find_apple(pair<int, int> target)
{
	for (int i = 0; i < apples.size(); ++i)
	{
		if (apples[i].isErase) continue;

		if (target.first == apples[i].x && target.second == apples[i].y) {
			apples[i].isErase = true;
			return true;
		}
	}

	return false;
}

char turn_snake(int time, char dir)
{
	for (auto a : turns)
	{
		if (a.time == time)
		{
			if (a.dir == 'L')
			{
				if (dir == 'D') return 'F';
				else if (dir == 'F') return 'L';
				else if (dir == 'L') return 'E';
				else return 'D';
			}
			else
			{
				if (dir == 'D') return 'E';
				else if (dir == 'F') return 'D';
				else if (dir == 'L') return 'F';
				else return 'L';
			}
		}
	}

	return dir;
}

int main()
{
	format;

	cin >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;

		apples.push_back({ x,y });
	}

	cin >> L;

	for (int i = 0; i < L; ++i)
	{
		int x;
		char c;
		cin >> x >> c;

		turns.push_back({ x, c }); // 시간, 방향
	}


	s.push_back({ 1, 1 });

	char dir = 'D'; // 이동방향
	int time = 0;
	while (++time)
	{
		pair<int, int> pos = s.back();

		if (dir == 'D')
		{
			//오른쪽
			pos = { pos.first, pos.second + 1 };
		}
		else if (dir == 'L')
		{
			//왼쪽
			pos = { pos.first, pos.second - 1 };
		}
		else if (dir == 'F')
		{
			//위
			pos = { pos.first - 1, pos.second };
		}
		else if (dir == 'E')
		{
			//아래
			pos = { pos.first + 1, pos.second };
		}

		if (pos.first <= 0 || pos.first > n || pos.second <= 0 || pos.second > n || bump(pos)) break;

		//사과 유무
		if (!find_apple(pos))
		{
			s.pop_front();
		}

		dir = turn_snake(time, dir);

		s.push_back(pos);
	}

	cout << time;

}