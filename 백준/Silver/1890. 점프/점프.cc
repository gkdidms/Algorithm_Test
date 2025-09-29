#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n;
vector<vector<int>> arr;

int main() {
  format;
  
  cin >> n;
  arr.resize(n, vector<int>(n));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> arr[i][j];
    }
  }

  vector<vector<long long>> dp(n, vector<long long>(n));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;

      int value = arr[i][j];
      int down = value + i;
      int right = value + j;

      if (down < n) dp[down][j] = dp[down][j] + dp[i][j];
      if (right < n) dp[i][right] = dp[i][right] + dp[i][j];
    }
  }

  cout << dp[n -1][n - 1];

  return 0;
}

