#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int x, y ,w, h;
  cin >> x >> y >> w >> h;

  int answer = min(x - 0, min(y - 0, min(w - x, h - y)));

  cout << answer;

}
