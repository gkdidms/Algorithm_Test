#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

double x, y, c;

double func(double mid)
{
  double h1 = sqrt(x * x - mid * mid);
  double h2 = sqrt(y * y - mid * mid);

  return (h1 * h2) / (h1 + h2);
}

int main() {
  format;

  cin >> x >> y >> c;
  
  double low = 0;
  double high = min(x, y);
  double answer = 0.0;

  while(high - low > 0.000001)
    {
      double mid = (high + low) / 2.0;

      if (func(mid) >= c)
      {
        answer = mid;
        low = mid;
      }
      else
        high = mid;
    }

  printf("%.3lf", answer);
}

