#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n;
vector<int> arr; 
int a, b;
int answer = int(1e9);

void dfs(){
  queue<pair<int, int>> q;
  q.push({a, 0});
  vector<bool> visible(n);
  visible[a] = true;

  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    if (cur.first == b){
      answer = min(answer, cur.second);
      continue;
    }

    for (int i = cur.first + arr[cur.first]; i <= n; i += arr[cur.first]){
      if(visible[i] ) continue;

      visible[i] = true;
      q.push({i, cur.second + 1});
    }
    for (int i = cur.first - arr[cur.first]; i >= 1; i -= arr[cur.first]){
      if (visible[i]) continue;
      visible[i] = true;
      q.push({i, cur.second + 1});
    }
  }
}

int main() {
  format;

  cin >> n;
  arr.resize(n + 1);

  for (int i = 1; i <= n; ++i){
    cin >> arr[i];
  }
    
  cin >> a>> b;

  dfs();
  
  if (answer == int(1e9)){
    cout << -1;
  }
  else
    cout << answer;

  return 0;
}

