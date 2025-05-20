#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, d;
  cin >> n;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i)
    {
      int h, o;
      cin >> h >> o;
      if (h > o)
        v[i] = {o, h};
      else v[i] = {h, o};
    }

  sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  });

  cin >> d;
  
  priority_queue<int, vector<int>, greater<int>> pq;
  int answer = 0;
  for (int i = 0; i < n; ++i)
    {
      int h = v[i].first; // 시작 시간
      int o = v[i].second; // 끝 시간

      if (o - h <= d) pq.push(h); // 끝 - 시작 <= 길이
      else continue;

      while(!pq.empty())
        {
          if (pq.top() < o - d) pq.pop(); // 시작 < 끝 - 길이(현재 idx의 끝 시간을 기준으로 계산한 범위 안에 포함이 되는가?)
          else 
          {
            answer = max((int)pq.size(), answer);
            break;
          }
        }
    }


  cout << answer;

  return 0;
}

