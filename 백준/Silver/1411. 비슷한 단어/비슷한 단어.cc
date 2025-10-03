#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool check(string s1, string s2) {
  int len = s1.size();
  int visible1[27] = {0, };
  int visible2[27] = {0, };
  bool isVisible = false;
  
  for (int i = 0; i < len; i++) {
      int idx1 = s1[i] - 'a' + 1;
      int idx2 = s2[i] - 'a' + 1;
      if (!visible1[idx1] && !visible2[idx2])
      {
          visible1[idx1] = idx2;
          visible2[idx2] = idx1;
      }
      else if(visible1[idx1] != idx2)
      {
          isVisible = true;
      }
  }
  return isVisible;
}

int main() {
  format;

  int n;
  cin >> n;

  vector<string> arr(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  int answer = 0;
  for (int i = 0; i < n - 1; ++i){
    for (int j = i + 1; j < n; ++j){
      if (check(arr[i], arr[j]) == false) answer++;
    }
  }

  cout << answer;

}
