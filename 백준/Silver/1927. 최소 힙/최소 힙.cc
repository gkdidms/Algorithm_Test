#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll long long
using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  
  for (int i = 0; i < n; ++i){
    ll temp;
    cin >> temp;

    if (temp == 0){
      if (pq.empty()){
        cout << 0 << '\n';
        continue;
      }
      ll anw = pq.top();
      cout << anw << '\n';
      pq.pop();
    }
    else{
      pq.push(temp);
    }
  }
}

