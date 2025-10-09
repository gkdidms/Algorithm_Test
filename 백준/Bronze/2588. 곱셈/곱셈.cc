#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  string str;
  int n;
  cin >> n >> str;

  cout << n * (str[2] - '0') << '\n';
  cout << n * (str[1] - '0') << '\n';
  cout << n * (str[0] - '0') << '\n';

  cout << n * atoi(str.c_str());

  
}
