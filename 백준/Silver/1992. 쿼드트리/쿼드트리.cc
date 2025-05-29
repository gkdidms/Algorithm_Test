#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
vector<vector<int>> graph;

void dfs(int x, int y, int size)
{
  if (size == 1)
  {
    cout << graph[x][y];
    return;
  }
  
  bool onlyZero = true;
  bool onlyOne = true;
  for (int i = x; i < x + size; ++i)
    {
      for (int j = y; j < y + size; ++j)
        {
          if (graph[i][j] == 0) onlyOne = false;
          if (graph[i][j] == 1) onlyZero = false;
        }
    }

  if (onlyOne)
  {
    cout << 1;
    return;
  }
  if (onlyZero)
  {
    cout << 0;
    return;
  }

  cout << "(";
  dfs(x, y, size / 2);
  dfs(x, y + size / 2, size / 2);
  dfs(x  + size / 2, y, size / 2);
  dfs(x  + size / 2, y + size / 2, size / 2);
  cout << ")";
}


int main() {
  format;

  int n;
  cin >> n;

  graph.resize(n, vector<int>(n));

  for (int i = 0; i < n; ++i)
    {
      string str; cin >> str;

      for (int j = 0; j < n; ++j)
        {
          graph[i][j] = str[j] - '0';
        }
    }

  dfs(0, 0, n);
  
}

