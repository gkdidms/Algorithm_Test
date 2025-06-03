#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >> n >> m;

  deque<int> dq;
  for (int i = 1; i <= n; ++i)
    dq.push_back(i);


  int answer = 0;
  for (int i = 0; i < m; ++i)
    {
      int temp, idx = 0;
      cin >> temp;

      for (int j = 0; j < (int)dq.size(); ++j)
        {
          if (dq[j] == temp)
          {
            idx = j;
            break;
          }
        }

      if (idx <= (int)dq.size() / 2)
      {
        while(dq.front() != temp)
          {
            dq.push_back(dq.front());
            dq.pop_front();
            answer++;
          }
      }
      else
      {
          while(dq.front() != temp)
          {
            dq.push_front(dq.back());
            dq.pop_back();
            answer++;
          }
      }
      dq.pop_front();
    }

  cout << answer;
}
