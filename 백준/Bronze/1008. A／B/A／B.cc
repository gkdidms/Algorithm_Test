#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  double a, b;
  cin >> a >> b;

  cout << setprecision(10) << a / b;
}
