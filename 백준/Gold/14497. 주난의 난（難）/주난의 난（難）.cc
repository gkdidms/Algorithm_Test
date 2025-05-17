#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
int n, m;
pair<int, int> player;
pair<int, int> target;
vector<vector<char>> graph;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool bfs()
{
  vector<vector<bool>> visible(n, vector<bool>(m));

  queue<pair<int ,int>> q;
  q.push(player);
  visible[player.first][player.second] = true;
  
  while(!q.empty())
    {
      auto cur = q.front();
      q.pop();

      if (cur.first == target.first && cur.second == target.second) return true;
      
      for (int i = 0; i < 4; ++i)
        {
          int x = cur.first + dx[i];
          int y = cur.second + dy[i];

          if (x < 0 || x >= n || y < 0 || y >= m || visible[x][y]) continue;

          visible[x][y] = true;

          if (graph[x][y] == '1')
            graph[x][y] = '0';
          else
            q.push({x, y});
        }
    }

  return false;
}

int main() {
  format;

  cin >> n >> m;
  cin >> player.first >> player.second >> target.first >> target.second;

  graph.resize(n, vector<char>(m));

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        cin >> graph[i][j];
    }

  player = {player.first - 1, player.second - 1};
  target = {target.first - 1, target.second - 1};

  int answer = 1;
  while(!bfs())
    answer++;

  cout << answer;

  return 0;
}

