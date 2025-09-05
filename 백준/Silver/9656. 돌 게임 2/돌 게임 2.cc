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

  //홀 -> sk, 짝 -> cy
  int cnt = 0;
  cnt = (n / 3) + (n % 3);
  if (cnt % 2 == 0) cout << "SK";
  else cout << "CY";

}
