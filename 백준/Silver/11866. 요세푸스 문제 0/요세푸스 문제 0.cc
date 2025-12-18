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
  for(int i = 0; i < n; ++i){
    int cnt = 0;
    while(cnt < k){
      if(arr[index].second == false){
        cnt++;
      }
      if(cnt < k){
        index = (index + 1) % n;
      }
    }

    arr[index].second = true;
    answer.push_back(arr[index].first);
    index = (index + 1) %n ;
  }

  cout << "<";

  for(int i = 0; i < n; ++i){
    if (i == n-1){
      cout << answer[i] << ">";
    }
    else cout << answer[i] << ", ";
  }

  
}
