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

  vector<int> arr(51);
  for (int i = 0; i < n; ++i){
    int temp;
    cin >> temp;
    arr[temp]++;
  }

  for (int i = n; i >= 0; --i){
    if (arr[i] == i){
      cout << i;
      return 0;
    }
  }


  cout << -1;
  

  return 0;
}

