#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int r,c,t;
vector<vector<int>> v;
int answer = 0;

void check_filter(int x, int y){
  vector<int> check;
  for (int i = x; i < x + 3; ++i){
    for (int j = y; j < y + 3; ++ j){
      check.push_back(v[i][j]);
    }
  }

  sort(check.begin(), check.end());
  if(check[4] >= t) answer++;
}

int main() {
  format;

  cin >> r>> c;
  v.resize(r, vector<int>(c));
  for(int i = 0; i < r; ++i)
    {
      for (int j = 0; j < c; ++j){
        cin >> v[i][j];
      }
    }

  cin >> t;

  for (int i = 0; i + 2 < r; ++i){
    for (int j = 0; j + 2 < c; ++j){
      check_filter(i,j);
    }
  }
  
  cout << answer;
}
