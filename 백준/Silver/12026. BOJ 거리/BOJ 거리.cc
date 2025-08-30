#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define INF int(1e9)
using namespace std;
int n;

int main() {
  format;

  string str;
  cin >> n >> str;
  vector<char> street(n + 1);
  for (int i = 1; i <= n; ++i)
    street[i] = str[i-1];

  vector<int> dp(n + 1, INF);
  dp[1] = 0;
  for (int i = 1; i < n; ++i){
    if (street[i] == 'B'){
      for (int j = i + 1; j <= n; ++j){
        if (street[j] == 'O') dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
      } 
    }
    else if (street[i] == 'O'){
      for (int j = i + 1; j <= n; ++j){
        if (street[j] == 'J') dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
      }
    }
    else if (street[i] == 'J'){
      for (int j = i + 1; j <= n; ++j){
        if (street[j] == 'B') dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
      }
    }
  }

  if (dp[n] == INF) cout << -1;
  else cout << dp[n];
}
