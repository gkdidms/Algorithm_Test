#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i)
    {
      int a;
      cin >> a;

      if (a  < x) cout << a<< " ";
    }

  return 0;
}

