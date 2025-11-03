#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 1);
  while(m--){
    int i, j, k;
    cin >> i >> j >> k;

    for (int a = i; a <= j; ++a){
      arr[a] = k;
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << arr[i] << " ";
  

  return 0;
}

