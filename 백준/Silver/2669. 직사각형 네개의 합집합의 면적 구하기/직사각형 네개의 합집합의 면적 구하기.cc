#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  vector<vector<bool>> arr(101, vector<bool>(101));

  int max_x = 0;
  int max_y = 0;
  for(int i = 0; i < 4; ++i){
    int x, y, a, b;
    cin >> x >> y >> a>> b;

    max_x = max(max_x, a);
    max_y = max(max_y, b);

    for (int j = x; j < a; ++j){
      for (int k = y; k < b; ++k){
        arr[j][k] = true;
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= max_x; ++i){
    for (int j = 1; j <= max_y; ++j){
      if (arr[i][j] == true) answer++;
    }
  }

  cout << answer;

  return 0;
}

