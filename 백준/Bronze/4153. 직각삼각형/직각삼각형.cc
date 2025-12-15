#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  while(true){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    if (arr[0] == 0 && arr[1]  == 0 && arr[2]  == 0) break;

    int max_int = max(arr[0], max(arr[1],arr[2]));

    int sum = 0;
    for (int i = 0; i < 3; ++i){
      if (arr[i] == max_int) continue;

      sum += arr[i] * arr[i];
    }
    bool answer = sum == max_int * max_int;

    if (answer == true) cout << "right" << '\n';
    else cout << "wrong" << '\n';
  }

  return 0;
}

