#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; ++i)
    cin >> arr[i];
  cin >> m;
  
  sort(arr.begin(), arr.end());
  
  int left = 1;
  int right = arr[n - 1];

  int answer = 0;
  while(left <= right){
    int mid = (left + right) / 2;

    int sum = 0;
    for(int i = 0; i < n; ++i){
      if (mid < arr[i])
        sum += mid;
      else sum += arr[i];
    }

    if(m >= sum){
      left = mid + 1;
      answer = mid;
    }
    else{
      right = mid - 1;
    }
  }

  cout << answer;
}
