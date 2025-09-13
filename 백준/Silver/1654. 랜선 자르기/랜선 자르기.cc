#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, k;
  cin >> k >> n;

  int height = 0;
  vector<int> arr(k);
  for (int i = 0; i < k; ++i){
    cin >> arr[i];
    if (height < arr[i]) height = arr[i];
  }
  
  long long start = 1;
  long long end = height;
  int answer = 0;
  while(start <= end){
    long long mid = (start + end) / 2;
    int cnt = 0;
    for (int i = 0; i < k; ++i){
      cnt += arr[i] / mid;
    }

    if (cnt >= n){
      start = mid + 1;
      if (answer < mid) answer = mid;
    }
    else end = mid - 1;
  }

  cout << answer;

  return 0;
}

