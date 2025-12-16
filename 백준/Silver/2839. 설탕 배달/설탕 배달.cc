#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;
  
  vector<int> dp(n + 1, int(1e9));
  dp[3] = 1;
  dp[5] = 1;
  for(int i = 6; i <= n; ++i){
      dp[i] = min(dp[i - 5] + 1, dp[i - 3] + 1);
  }

  if (dp[n] >= int(1e9)) cout << "-1";
  else cout << dp[n];
  
}
