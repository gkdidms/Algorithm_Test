#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> visible;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void check_cheez()
{
  queue<pair<int, int>> q;
  q.push({0, 0});

  while(!q.empty())
    {
      auto cur = q.front();
      q.pop();

      for (int i = 0; i < 4; ++i)
        {
          int x = cur.first + dx[i];
          int y = cur.second + dy[i];

          if (x < 0 || x >= n || y < 0 || y >= m) continue;

          if (board[x][y] == 0 && !visible[x][y])
          {
            visible[x][y] = 1;
            q.push({x, y});
          }
          else if (board[x][y] == 1)
          {
            visible[x][y] += 1;
          }
        }
    }
}

bool isFinished()
{
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        {
          if (board[i][j] == 1) return false;
        }
    }

  return true;
}

int main() {
  format;

  cin >> n >> m;
  board.resize(n, vector<int>(m));

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        cin >> board[i][j];
    }

  int time = 0;
  while(true)
    {
      visible.clear();
      visible.resize(n, vector<int>(m));
      
      check_cheez();
      time++;
      
      //치즈 업데이트
      for (int i = 0; i < n; ++i)
        {
          for (int j = 0; j < m; ++j)
            {
              if (visible[i][j] >= 2)
                board[i][j] = 0;
            }
        }

      if (isFinished()) break;
    }

  cout << time;
  return 0;
}

