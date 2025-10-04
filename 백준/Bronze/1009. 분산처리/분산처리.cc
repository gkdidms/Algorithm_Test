#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll unsigned long long
using namespace std;

int main() {
  format;

  int t;
  cin >> t;

  while(t--){
    int a, b;
    cin >> a>> b;

    int result = 1;
    int base = a % 10;
    for (int i = 0; i < b; ++i){
      result = (result * base) % 10;
    }

    if (result == 0) cout << 10 << '\n';
    else cout << result << '\n';
  }

  return 0;
}

