#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int k;
int main() {
  format;

  cin >> k;

  int size = 1;
  while(size < k)
    size *= 2;

  int cnt = 0;
  int temp = size;
  int copy = 0;
  while(k != 0)
    {
      if (k >= temp)
      {
        copy = cnt;
        k -= temp;
      }
      
      temp /= 2;
      cnt += 1;
    }

  cout << size << " " << copy;
}

