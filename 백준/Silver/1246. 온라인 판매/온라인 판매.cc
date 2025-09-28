#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >> n >> m;

  vector<int> arr(m);  
  for(int i = 0; i < m; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end(), greater<>());

  int min_place = int(1e9);
  int sum_place = 0;
  for(int i = 0; i < m; ++i){
    int test = 0;
    int place = arr[i];
    for (int j = 0; j < m; ++j){
      if (j >= n) break;
      if (place > arr[j]) break;
      test+= place;
    }

    if (sum_place < test){
      sum_place = test;
      min_place = arr[i];
    }
  }


  cout << min_place << " " << sum_place;
    
  

  return 0;
}

