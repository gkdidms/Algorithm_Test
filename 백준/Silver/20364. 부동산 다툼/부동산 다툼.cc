#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int x, n, q;
  cin >> n >> q;
  vector<bool> DP(2 << 20);
  while(q--){
    cin >> x;
    int answer = 0;
    int tempX = x;

    while(tempX > 1){
      if (DP[tempX]){
        answer = tempX;
      }
      int nextX = tempX/2;
      tempX = nextX;
    }
    DP[x] = true;
    cout << answer << '\n';
  }
}
