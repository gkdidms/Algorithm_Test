#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int a,b,v;
  cin >> a>> b>> v;

  if (a == v) cout << 1;
  else {
    if ((v - a) % (a - b) == 0) cout << ((v - a) / (a - b) + 1);
    else cout << ((v - a) / (a - b) + 2);
  }

  return 0;
}

