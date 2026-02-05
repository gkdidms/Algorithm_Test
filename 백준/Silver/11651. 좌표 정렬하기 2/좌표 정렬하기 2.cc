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

  vector<pair<int,int>> arr(n);
  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;

    arr[i] = {x, y};
  }

  sort(arr.begin(), arr.end(), [](auto a, auto b){
    if(a.second == b.second)
      return a.first < b.first;

    return a.second < b.second;
  });

  for(auto a : arr){
    cout << a.first << " " << a.second << '\n';
  }

}
