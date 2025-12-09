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
  vector<int> v;
  for(int i = 0; i < n; ++i){
        cin >> arr[i];
    v.push_back(arr[i]);
  }


  //1. 오름차순 정렬
  sort(arr.begin(), arr.end());

  //2. 중복 요소 제거
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  
  //3. 압축 배열의 요소값 탐색
  for (int i = 0; i < n; ++i){
    int idx = lower_bound(arr.begin(), arr.end(), v[i]) - arr.begin();
    cout << idx << " ";
  }

  return 0;
}

