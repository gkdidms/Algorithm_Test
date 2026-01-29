#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  string str;
  cin >> str;

  vector<char> arr;
  for(int i = 0; i < (int)str.size(); ++i){
    arr.push_back(str[i]);
  }

  sort(arr.begin(), arr.end(), greater<>());

  for(auto a : arr){
    cout << a;
  }
}
