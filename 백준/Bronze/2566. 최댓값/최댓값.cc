#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;
  
  int max = -1, r = 0, c = 0;
  for (int i = 1; i <= 9; ++i){
    for (int j = 1; j <= 9; ++j){
      int temp;
      cin >> temp;

      if (temp > max){
        max = temp;
        r = i; c = j;
      }
    }
  }

  cout << max << '\n';
  cout << r << " " << c;
  

  return 0;
}

