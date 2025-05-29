#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;
  
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end(), [](const auto& a,  const auto& b) {
    if (a.first == b.first) return a.second < b.second;

    return a.first < b.first;
  });

  priority_queue<int, vector<int>, greater<int>> pq;

  int answer = 0;
  for (int i = 0; i < n; ++i)
    {
      if (!pq.empty())
      {
        if (pq.top() <= v[i].first)
          pq.pop();
      }

      pq.push(v[i].second);
      answer = max(answer, (int)pq.size());
    }

  cout << answer;
}

