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
  vector<int> table(n);
  vector<long long> sums(n + 1);
  for (int i = 0; i < n; ++i){
    cin >> table[i];
    sums[i + 1] = table[i] + sums[i];
  }

  long long answer = 0;
  for (int i = 0; i < n - 1; ++i){
    answer += table[i] * (sums[n] - sums[i + 1]);
  }

  cout <<  answer;

  return 0;
}

