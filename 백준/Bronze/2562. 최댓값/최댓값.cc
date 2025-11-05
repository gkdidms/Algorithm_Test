#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  vector<pair<int, int>> arr;
  for (int i = 0; i < 9; ++i){
    int temp;
    cin >> temp;

    arr.push_back({i, temp});
  }

  sort(arr.begin(), arr.end(), [](auto& a, auto& b){
    return a.second > b.second;
  });

  cout << arr[0].second << '\n' << arr[0].first + 1;

  

  return 0;
}

