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
  vector<int> arr(n);
  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end(), greater<>());

  int answer = 0;
  for (int i = 0; i < n; ++i)
    answer = max(answer, arr[i] + i + 1);

  cout << answer + 1;

  return 0;
}

