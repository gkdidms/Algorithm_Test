#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
  int n, c;
  vector<int> arr;
bool isInstall(int dist){
  int cnt = 1;
  int lastpos = arr[0];

  for(int i = 1; i < n; ++i){
    if(arr[i] - lastpos >= dist){
      cnt++;
      lastpos = arr[i];
    }
  }

  return cnt >= c;
}

int main() {
  format;
  
  cin >> n >> c;

  arr.resize(n);
  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  //거리를 비교
  int left = 1;
  int right = arr[n-1] - arr[0];

  int answer = 0;
  while(left <= right){
    int mid = (left + right) / 2;
    if(isInstall(mid) == true){
      answer = mid;
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }
  cout << answer;
}
