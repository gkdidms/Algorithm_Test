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

  if( n >= 90 && n <= 100) cout << "A" ;
  else if (n >= 80 && n <= 89) cout << "B";
  else if (n >= 70 && n <= 79) cout << "C";
  else if (n >= 60 && n <= 69) cout << "D";
  else cout << "F";

  

  return 0;
}

