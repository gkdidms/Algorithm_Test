#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int k;
  cin >> k;

  string str = "";
  while(k > 0)
    {
      int n = k % 2;
      k = k / 2;

      if (n == 0)
      {
        k -= 1;
        str = '7' + str;
      }
      else str = '4' + str;
    }

  cout << str;
  

  return 0;
}

