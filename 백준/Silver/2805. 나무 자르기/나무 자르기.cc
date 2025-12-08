#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll long long

using namespace std;

int main() {
  format;

  ll n, m;
  cin >> n >> m;

  ll start = 0;
  ll end = 0;

  vector<ll> arr(n);
  for (int i = 0; i < n; ++i){
    cin >> arr[i];
    end = max(end, arr[i]);
  }

  ll answer = 0;
  while (start <= end){
    ll mid = start + (end - start) / 2;

    ll check = 0;
    for (auto a : arr){
      if (mid >= a) continue;

      check += a - mid;
    }

    if (check < m){
      end = mid - 1;
    }
    else if (check >= m){
      answer = mid;
      start = mid + 1;
    }
  }

  cout << answer;
}

