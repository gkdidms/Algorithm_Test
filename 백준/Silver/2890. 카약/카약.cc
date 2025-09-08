#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int r, c;
  cin >> r >> c;
  vector<pair<int, int>> arr;

  for (int i = 0; i < r; ++i){
    string str;
    cin >> str;

    for (int j = 0; j < c; ++j){
      int idx = str[j] - '0';
      if (idx >= 1 && idx <= 9){
        //숫자일때
        arr.push_back({idx, j});
        break;
      }
    }
  }

  sort(arr.begin(), arr.end(), [](auto& a, auto& b){
    return a.second >= b.second;
  });

  vector<int> answer(10);
  int cnt = 1;
  int last_int = 0;
  for (auto a : arr){
    if (last_int == a.second) cnt--;
    answer[a.first] = cnt++;
    last_int = a.second;
  }

  for (int i = 1; i <= 9; ++i)
    cout << answer[i] << '\n';
}
