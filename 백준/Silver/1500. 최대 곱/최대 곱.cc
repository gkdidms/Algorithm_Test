#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int s, k;
  cin >> s >> k;

  long long answer = 1;

  int temp1 = s / k;
  int temp2 = s % k;

  for (int i = 0; i < k; ++i)
    {
      if (temp2 > 0)
      {
        answer *= (temp1 + 1);
        temp2--;
      }
      else answer *= temp1;
    }
  cout << answer;
}
