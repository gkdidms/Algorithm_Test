#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  int cnt = n - 1;
  int answer = 0;
  for (int i = 0; i < k; ++i){
    answer += (arr[cnt--] - i);
  }

  cout << answer;

  

  return 0;
}

