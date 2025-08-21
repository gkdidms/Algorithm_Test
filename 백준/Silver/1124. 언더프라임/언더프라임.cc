#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool isPrime(int n){
  if (n <= 1) return false;
  for(int i = 2; i <= sqrt(n); ++i){
    if (n % i == 0) return false;
  }
  return true;
}

vector<int> primeFectorization(int n){
  vector<int> factors;
  for (int i = 2; i * i <= n; ++i){
    while(n % i == 0){
      factors.push_back(i);
      n /= i;
    }
  }

  if (n > 1) factors.push_back(n);

  return factors;
}

vector<int> getUniquePrimes(const vector<int>& factors){
  vector<int> uniquePrimes;
  for (int factor: factors){
    if (isPrime(factor) == true)
      uniquePrimes.push_back(factor);
  }

  return uniquePrimes;
}

int main() {
  format;

  int a, b;
  cin >> a>> b;

  int cnt = 0;
  for (int i = a; i <= b; ++i){
    vector<int> factors = primeFectorization(i);
    vector<int> primes = getUniquePrimes(factors);

    int size = primes.size();

    if (isPrime(size) == true) cnt++;
  }

  cout << cnt;
  
}
