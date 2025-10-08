#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int d, h, w;
  cin >> d >> h >> w;

  int a= h * h + w * w;
  double temp = sqrt(a);
  double temp2 = d / temp;

  cout << floor(h * temp2) << " " << floor(w * temp2);
}
