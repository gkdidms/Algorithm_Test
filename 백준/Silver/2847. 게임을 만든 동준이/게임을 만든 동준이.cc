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

  int cnt = 0;
  for (int i = n-1; i > 0; --i){
    if (arr[i] <= arr[i-1]){
      int temp = arr[i-1] - arr[i] + 1;
      arr[i-1] -= temp;
      cnt += temp;
    }
  }

  cout << cnt;
  

  return 0;
}

