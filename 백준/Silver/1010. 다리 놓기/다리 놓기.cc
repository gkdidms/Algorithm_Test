#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int t;
  cin >> t;
      int dp[32][32] = {0};
    
    for(int i = 1; i < 31; ++i){
      for(int j = i; j < 31; ++j){
        if(i == 1)
          dp[i][j] = j;
        else if (i == j)
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
      }
    }
  
  while(t--){
    int n, m;
    cin >> n >> m;


    cout << dp[n][m] << '\n';
  }
}

