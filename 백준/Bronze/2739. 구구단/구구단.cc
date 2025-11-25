#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  for (int i = 1; i <= 9; ++i){
    cout << n << " * " << i << " = " << n * i << '\n'; 
  }

}
