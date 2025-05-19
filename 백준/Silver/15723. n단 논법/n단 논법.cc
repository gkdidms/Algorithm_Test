#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m;

vector<vector<int>> N;

bool isConclusion(int a, int target)
{
  vector<bool> visible(26);
  queue<int> q;
  q.push(a);

  while(!q.empty())
    {
      int cur = q.front();
      q.pop();

      if (cur == target)
      {
        return true;
      }
      for (const int next : N[cur])
        {
          if (visible[next]) continue;

          visible[next] = true;
          q.push(next);
        }
    }

  return false;
}

int main() {
  format;

  cin >> n;

  N.resize(26);
  for (int i = 0; i < n; ++i)
    {
      char a, b;
      string str;
      cin >> a >> str >> b;

      N[a - 'a'].push_back(b - 'a');
    }

  cin >> m;
  for (int i = 0; i < m; ++i)
    {
      char a, b;
      string str;
      cin >> a >> str >> b;

      if (isConclusion(a - 'a', b- 'a') == true)
        cout << "T" << '\n';
      else cout << "F" << '\n';
    }

  
  return 0;
}

