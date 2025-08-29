#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool isPrime(int n){
  if (n <= 1) return false;

  for (int i = 2; i * i <= n; ++i){
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  format;

  int n;
  cin >> n;

  int max_prime = 2;
  int answer = 0;
  vector<int> primes;
  primes.push_back(2);
  while(true){
    if (n < answer) break;

    max_prime++;
    if (isPrime(max_prime)){
      answer = primes[primes.size() - 1] * max_prime;

      primes.push_back(max_prime);
    }
  }

  cout << answer;

  return 0;
}

