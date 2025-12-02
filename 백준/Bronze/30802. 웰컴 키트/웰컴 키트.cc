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

  vector<int> arr(6);
  int sum = 0;
  for (int i = 0; i < 6; ++i){
    cin >> arr[i];
    sum += arr[i];
}
  int t, p;
  cin >> t >> p;

  int t_sum = 0;
  for (auto a : arr){
    if (a % t == 0) t_sum += (a / t);
    else t_sum += (a / t) + 1;
  }

  cout << t_sum << '\n';
  cout << sum / p << " " << sum % p ;

  return 0;
}

