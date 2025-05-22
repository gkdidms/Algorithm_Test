#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, d, k, c;
  cin >> n >> d >> k >> c;

  vector<int> v(n);
  vector<int> sushi(d + 1);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  deque<int> dq;
  int answer = 0;
  int cnt = 0;

  for (int i = 0; i < k; ++i)
    {
      int temp = 0;

      dq.push_back(v[i]);

      if (!sushi[v[i]]) cnt++;
      sushi[v[i]]++;
    }

  answer = cnt;

  for (int i = 0; i < n; ++i)
    {
      int first = dq.front();
      dq.pop_front();
      sushi[first]--;
      if(!sushi[first]) cnt--;

      int idx = (i + k) % n;
      dq.push_back(v[idx]); // 원형이니 처음으로 돌아가는 형태
      if (!sushi[v[idx]]) cnt++;
      sushi[v[idx]]++;

      if (!sushi[c])
        answer = max(answer, cnt+1);
      else answer = max(answer, cnt);
    }

  cout << answer;

  
}

