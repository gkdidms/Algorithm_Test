#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int r, c;

int main() {
  format;

  cin >> r >> c;

  vector<string> v(r);

  for (int i = 0; i < r; ++i){
    cin >> v[i];
  }
  vector<string> answer;
  
  for(int i = 0; i < r; ++i){
    string str = "";
    for (int j = 0; j < c; ++j){
      if (v[i][j] == '#'){
        if (str.size() > 1){
          answer.push_back(str);

        }
                  str = "";
          continue;
      }
      else{
        str.push_back(v[i][j]);
      }
    }
    if (str.size() > 1){
      answer.push_back(str);
    }
  }

  for(int j = 0; j < c; ++j){
    string str = "";
    for (int i = 0; i < r; ++i){
      if (v[i][j] == '#'){
        if (str.size() > 1){
          answer.push_back(str);

        }
                  str = "";
          continue;
      }
      else{
        str.push_back(v[i][j]);
      }
    }
    if (str.size() > 1){
      answer.push_back(str);
    }
  }

  if (answer.size() > 0) {
      sort(answer.begin(), answer.end());
      cout << answer[0];
  }

}
