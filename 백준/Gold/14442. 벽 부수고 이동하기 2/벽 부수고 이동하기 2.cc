#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m, k;
vector<vector<int>> board;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct node {
  int x, y, k, cnt;

  bool operator<(const node& a) const {
    return cnt > a.cnt;
  };
};

int bfs()
{
  vector<vector<vector<bool>>> visible(n, vector<vector<bool>>(m, vector<bool>(k + 1)));
  priority_queue<node> pq;
  pq.push({0, 0, k, 1});

  while(!pq.empty())
    {
      auto cur = pq.top();
      pq.pop();

      if (cur.x + 1 == n && cur.y + 1 == m) return cur.cnt;

      for (int i = 0; i <4; ++i)
        {
          int x = cur.x + dx[i];
          int y = cur.y + dy[i];

          if (x < 0 || x >= n || y < 0 || y >= m || visible[x][y][cur.k]) continue;

          
          if (board[x][y] == 1 && cur.k > 0)
          {
            visible[x][y][cur.k] = true;
            pq.push({x, y, cur.k - 1, cur.cnt + 1});
          }
          else if (board[x][y] == 0) {
            visible[x][y][cur.k] = true;
            pq.push({x, y, cur.k, cur.cnt + 1});
          }
        }
    }

  return -1;
}

int main() {
  format;

  cin >> n >> m >> k;
  board.resize(n, vector<int>(m));

  for (int i = 0; i < n; ++i)
    {
      string str;
      cin >> str;

      for (int j = 0; j < str.size(); ++j)
        board[i][j] = str[j] - '0';
    }

  cout << bfs();
  
  return 0;
}

