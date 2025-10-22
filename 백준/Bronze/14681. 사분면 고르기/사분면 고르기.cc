#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int x, y;
  cin >> x >>y;

  if (x > 0 && y > 0) cout << 1;
  else if (x > 0 && y < 0) cout << 4;
  else if (x < 0 && y < 0) cout << 3;
  else if (x < 0 && y > 0) cout << 2;

}
