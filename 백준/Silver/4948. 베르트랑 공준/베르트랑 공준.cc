#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool recursion(int n){
  if (n <= 1) return false;
  
  for (int i = 2; i <= sqrt(n); ++i){
    if (n % i == 0) return false;
  }

  return true;
}

int main() {
  format;

  //임의의 자연수 n에 대하여, n보다 크고, 2n 보다 작거나 같은 소수는 적어도 하나 존재한다

  int n ;
  while(true){
    cin >> n;
    if (n == 0) break;
    int cnt = 0;
    for (int i = n + 1; i <= 2*n; ++i){
      if (recursion(i) == true) cnt++;
    }

    cout << cnt << '\n';
  }
}
