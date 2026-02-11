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
  for(int i = 0; i<n; ++i) cin >> arr[i];
  
  sort(arr.begin(), arr.end());
  
  cin >> m;
  
  for(int i = 0; i < m; ++i){
   int temp = 0; 
    cin >> temp;

    int left = 0;
    int right= n;
    int answer = 0;
    while(left <= right){
      int mid = (left + right) / 2;
      if(mid == n)
        break;
      if(arr[mid] < temp){
        left = mid + 1;
      }
      else if(arr[mid] > temp){
        right = mid - 1;
      }
      else{
        answer = 1;
        break;
      }
    }
    cout << answer << " "; 
  }
}
