#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >>  n >> m;

  vector<string> S(n);
  for (int i = 0; i < n; ++i)
    {
      cin >> S[i];
    }

  sort(S.begin(), S.end());

  int answer = 0;

  for (int i = 0; i < m; ++i)
    {
      string str;
      cin >> str;

      int left = 0, right = S.size() - 1;

      while(left <= right)
        {
          int mid = (left + right) / 2;

          auto idx = S[mid].find(str);
          if (idx != string::npos && (int)idx == 0)
          {
            answer++;
            break;
          }

          if (S[mid] < str)
            left = mid + 1;
          else right = mid - 1;
        }
    }

  cout << answer;

}

