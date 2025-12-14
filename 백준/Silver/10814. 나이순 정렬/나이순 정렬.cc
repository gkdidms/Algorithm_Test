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

  vector<pair<string, int>> arr(n);

  for (int i = 0; i < n; ++i){
    string name;
    int age;
    cin >> age>> name;

    arr[i] = {name, age};
  }

  stable_sort(arr.begin(), arr.end(), [](auto& a, auto& b){
    return a.second < b.second;
  });

    for (auto a : arr){
    cout << a.second << " " << a.first << '\n';
    }
  

  return 0;
}

