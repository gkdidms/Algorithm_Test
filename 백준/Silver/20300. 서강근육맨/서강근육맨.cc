#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll long long
using namespace std;

int n;
ll answer = pow(10, 18);
vector<ll> arr;

int main() {
  format;

  cin >> n;

  arr.resize(n);
  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  if(n % 2 == 1){
    answer = arr[n - 1];
    n--;
    for(int i = 0; i < n / 2; ++i){
      ll m = arr[i] + arr[(n - 1) - i];
      answer = max(m, answer);
    }
  }
  else{
        for(int i = 0; i < n / 2; ++i){
      ll m = arr[i] + arr[(n - 1) - i];
      answer = max(m, answer);
    }
  }
  cout << answer;
}
