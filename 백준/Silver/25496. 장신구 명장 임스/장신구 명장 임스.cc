#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int p, n;
  cin >> p >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  int answer = 0;
  for (auto a : arr){
    if (200 <= p) break;

    p += a;
    answer++;
  }

  cout << answer;

  return 0;
}

