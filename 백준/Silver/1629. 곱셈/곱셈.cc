#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

long long calculate(long long a, long long b, long long c)
{
  if (b == 1) return a % c;

  long long temp = calculate(a, b / 2, c) % c;

  if (b % 2 == 0)
    return temp * temp % c;
  else 
    return temp * temp % c * a % c;
}

int main() {
  format;

  long long a, b, c;
  cin >> a>> b>> c;

  cout << calculate(a,b,c);

  return 0;
}

