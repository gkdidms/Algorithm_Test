#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;


  while(true){
    int n;
    cin >> n;

    if (n == 0) break;

    vector<pair<string, double>> arr;
    for(int i = 0; i < n; ++i){
      string name;
      double height;
      cin >> name >> height;

      arr.push_back({name, height});
    }

    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b){
      return a.second > b.second;
    });

    double max_int = arr[0].second;

    for (auto& a : arr){
      if (max_int <= a.second){
        cout << a.first << " ";
      }
    }

    cout << '\n';
  }

  

  return 0;
}

