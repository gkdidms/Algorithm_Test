#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll long long

using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  int A[4001], B[4001], C[4001], D[4001];
  for (int i = 0; i < n; ++i)
    {
      cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

  vector<int> sum;
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
        sum.push_back(A[i] + B[j]);
    }

  sort(sum.begin(), sum.end());

  ll answer = 0;
  for (int i = 0; i < n; ++i)
    {
      int value = 0;
      for (int j = 0; j < n; ++j)
        {
          value = C[i] + D[j];
          answer += upper_bound(sum.begin(), sum.end(), -value) - lower_bound(sum.begin(), sum.end(), -value);
        }
    }

  cout << answer;

  return 0;
}

