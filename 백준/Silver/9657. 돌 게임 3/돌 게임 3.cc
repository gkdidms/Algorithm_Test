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

  vector<int> dp(n + 1);
  dp[1] = dp[3] = dp[4] = dp[5] = 1;
  dp[2] = 0;

  for (int i = 6; i <= n; ++i){
    if(dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) dp[i] = 1;
    else dp[i] = 0;
  }

  if (dp[n] == 0) cout << "CY";
  else cout << "SK";
  return 0;
}

