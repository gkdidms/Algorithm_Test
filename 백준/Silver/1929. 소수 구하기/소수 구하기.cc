#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >> n >> m;

  vector<bool> arr(1'000'001);
  arr[0] = true;
  arr[1] = true;
  
  for (int i = 2; i <= sqrt(m); ++i){
    if (arr[i] == true) continue;

    for (long long j = i * i; j <= m; j += i){
      arr[j] = true;
    }
  }

  for (int i = n; i <=m; ++i){
    if (arr[i] == true) continue;

    cout << i << '\n';
  }
}
