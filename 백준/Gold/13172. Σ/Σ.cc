#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll long long
#define MOD 1'000'000'007

using namespace std;

ll func(ll x, ll y)
{
  if (y == 1) return x;
  if (y % 2 == 1) return x * func(x, y - 1) % MOD;

  ll p = func(x, y/2);
  return p * p % MOD;
}

int main() {
  format;

  ll m;
  cin >> m;

  ll answer = 0;
  while(m--)
    {
      ll a, b;
      cin >> a >> b;

      //기약 분수 형태로 만들기
      ll g = gcd(b,a); // 최대공약수
      b /= g;
      a /= g;

      answer += b * func(a, MOD - 2) % MOD; // b ^ (X - 2);
      answer %= MOD;
    }

  cout << answer;

  return 0;
}

