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
  vector<long long> arr(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  
  // 가장 큰 진약수를 찾기
  sort(arr.begin(), arr.end(), greater<long long>());

  ll answer = arr[0] * arr[n - 1];
  cout << answer;
  return 0;
}
