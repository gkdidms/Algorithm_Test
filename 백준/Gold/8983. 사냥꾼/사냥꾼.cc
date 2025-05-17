#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int m, n, l;

  cin >> m >> n >> l;

  vector<int> M(m);
  for (int i = 0; i < m; ++i)
    cin >> M[i];

  sort(M.begin(), M.end());

  int answer = 0;
  for (int i = 0; i < n; ++i)
    {
      int x, y;
      cin >> x >> y;

      if (y > l) continue;

      int left = 0;
      int right = M.size() - 1;

      int lower = x + y - l;
      int upper = x - y + l;

      while(left <= right)
        {
          int mid = (left + right) / 2;

          if (lower <= M[mid] && upper >= M[mid])
          {
            answer++;
            break;
          }
          else if (lower > M[mid])
            left = mid + 1;
          else if (upper < M[mid])
            right = mid - 1;
        }
      
    }

  cout << answer;

  return 0;
}

