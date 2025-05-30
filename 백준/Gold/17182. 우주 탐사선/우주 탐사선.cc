#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
int n, k;
int answer = int(1e9);
vector<vector<int>> dist;
vector<bool> visible;

void per(int cur, int depth, int time)
{
  if (depth == n -1)
  {
     answer = min(answer, time);
    return;
  }

  for (int i = 0; i < n; ++i)
    {
      if (visible[i]) continue;
      visible[i] = true;
      per(i, depth + 1, time + dist[cur][i]);
      visible[i] = false;
    }
}

int main() {
  format;

  cin >> n >> k;
  dist.resize(n, vector<int>(n));
  visible.resize(n);
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
        cin >> dist[i][j];
    }

  for (int k = 0; k < n; ++k)
    {
      for (int i = 0; i < n; ++i)
        {
          for (int j = 0; j < n; ++j)
            dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
        }
    }

  visible[k] = true;
  per(k, 0, 0);

  cout << answer;
  
}

