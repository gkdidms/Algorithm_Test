#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false; // 0과 1은 소수가 아니다

    for (int i = 2; i <= sqrt(n); ++i)
      {
        if (n % i == 0) return false; // 나누어 떨어지면 소수 x
      }

  return true;
}

int main() {
  format;

  int t;
  cin >> t;
  
  while(t--)
    {
      int k;
      cin >> k;

      //합성수인가?
      if(isPrime(k) || k == 1) 
      {
        cout << 0 << '\n';
        continue;
      }

      int left = k - 1;
      int right = k + 1;

      while(left >= 2 && !isPrime(left))
        {
          left -= 1;
        }
        

      while(!isPrime(right))
        {
          right += 1;
        }
        

      cout<< right - left << '\n';
      
    }
}

