#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int a, k;
int answer = int(1e9);

void bfs(int n, int cnt){
  queue<pair<int, int>> q; // a, cnt
  vector<bool> visible(1'000'001);
  q.push({n, 0});
  visible[a] = true;

  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    if (cur.first == k){
      answer = min(answer, cur.second);
    }

    if (cur.first * 2 <= k && !visible[cur.first * 2]){
      visible[cur.first * 2] = true;
      q.push({cur.first * 2, cur.second + 1});
    }
    if (cur.first + 1 <= k && !visible[cur.first + 1]){
      visible[cur.first + 1] = true;
      q.push({cur.first + 1, cur.second + 1});
    }
  }
}

int main() {
  format;

  cin >> a >> k;
  
  bfs(a, 0);
  cout << answer;

  return 0;
}

