#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
  int n, k;
bool check(vector<pair<int, bool>>& arr){
  for (int i = 0; i < n; ++i){
    if(arr[i].second == false) return false;
  }

  return true;
}
int main() {
  format;


  cin >> n >> k;

  vector<pair<int, bool>> arr;
  for (int i = 1; i <= n; ++i)
    arr.push_back({i, false});

  vector<int> answer;
  int index = 0;
  while(check(arr) == false){
    int count = 0;
    // 제거되지 않은 사람만 세면서 k번째 찾기
    while(count < k){
      if(arr[index].second == false){  // 아직 제거 안된 사람만 카운트
        count++;
      }
      if(count < k){  // k번째 도달 전까지만 이동
        index = (index + 1) % n;
      }
    }
    arr[index].second = true;
    answer.push_back(arr[index].first);
    // 다음 시작 위치로 이동
    index = (index + 1) % n;
  }

  cout << "<";

  for(int i = 0; i < n; ++i){
    if (i == n-1){
      cout << answer[i] << ">";
    }
    else cout << answer[i] << ", ";
  }

  
}
