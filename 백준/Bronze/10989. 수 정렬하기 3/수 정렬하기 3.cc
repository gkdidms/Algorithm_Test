#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;
  map<int, int> arr;
  for(int i = 0; i < n; ++i){
     int a;
    cin >> a;

    arr[a]++;
  }

  for (auto a : arr){
    for (int i = 0; i < a.second; ++i)
      cout << a.first << '\n';
  }
}
