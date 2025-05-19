#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

struct node
{
  int x, y, cnt;
};

int move(int l, pair<int, int> start, pair<int, int> goal)
{
  vector<vector<bool>> visible(l, vector<bool>(l));
  queue<node> q;
  q.push({start.first, start.second, 0});

  while(!q.empty())
    {
      auto cur = q.front();
      q.pop();

      if (cur.x == goal.first && cur.y == goal.second)
      {
        return cur.cnt;
      }
      
      for (int i = 0; i < 8; ++i)
        {
          int x = cur.x + dx[i];
          int y = cur.y + dy[i];

          if (x < 0 || x >= l || y < 0 || y >= l || visible[x][y]) continue;

          visible[x][y] = true;
          q.push({x, y, cur.cnt + 1});
        }
    }

  return 0;
}

int main() {
  format;

  int t;
  cin >> t;

  while(t--)
    {
      int l;
      cin >> l;

      pair<int, int> cur;
      pair<int, int> goal;

      cin >> cur.first >> cur.second;
      cin >> goal.first >> goal.second;

      cout << move(l, cur, goal) << '\n';
      
    }
  

  return 0;
}

