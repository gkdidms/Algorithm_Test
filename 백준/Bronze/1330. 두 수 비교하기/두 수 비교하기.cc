#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int a, b;
  cin >> a>> b;

  if (a > b) cout << ">";
  else if (a < b) cout << "<";
  else if (a == b) cout << "==";

  

}
