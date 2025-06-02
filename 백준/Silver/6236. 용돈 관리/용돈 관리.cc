#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >> n >> m;

  int total = 0;
  vector<int> k(n);
  for (int i = 0; i < n; ++i)
    {
      cin >> k[i];  
      total += k[i];
    }
    
  
  int start = 1, end = total;
  int cost = 0, answer = 0;
  while(start <= end)
    {
      int mid = (start + end) / 2;
      cost = mid; // 현재 남은 금액
      int cnt = 1;
      bool isPass = true;
      for (int i = 0; i < n; ++i)
        {
          if (k[i] > mid) // 하루 쓸 돈이 인출 금액보다 큰 경우
          {
            isPass = false;
            break;
          }
          if (k[i] > cost) // 하루 쓸 돈이 현재 남아있는 돈보다 클 경우
          {
            cost = mid;
            cnt++;
          }
          cost -= k[i]; // 하루 쓸 돈 차감
        }

      if (!isPass || cnt > m)
        start = mid + 1;
      else 
      {
        answer = mid;
        end = mid - 1;
      }
    }
  
  cout << answer;
}
