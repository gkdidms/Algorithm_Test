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

  vector<int> state(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> state[i];

  int student;
  cin >> student;

  for (int i = 0; i < student; ++i)
    {
      int temp, num;
      cin >> temp >> num;

      if (temp == 1){
        //남
        for (int j = num; j <= n; j += num){
          state[j] = state[j] == 0 ? 1 : 0;
        }
      }
      else if (temp == 2){
        //여
        int left = num, right = num;
        while(true){
          left -= 1;
          right += 1;

          if (left <= 0 || right > n ||
              (state[left] != state[right])){
            left += 1;
            right -= 1;
            break;
              }
        }
        //변하지 않음
        if (left == num && right == num){
          state[num] = state[num] == 0 ? 1 : 0;
        }
        else{
          for (int j = left; j <= right; ++j){
            state[j] = state[j] == 0 ? 1 : 0;
          }
        }
      }
    }

  for (int i = 1; i <= n; ++i){
    cout << state[i] << " ";
    if (i % 20 == 0)
      cout << '\n';
  }
    
}
