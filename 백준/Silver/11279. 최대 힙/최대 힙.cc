#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  priority_queue<ll> pq;
  for(int i = 0; i < n; ++i){
    ll temp;
    cin >> temp;


    if (temp == 0){
      if(pq.empty()){
        cout << "0" << '\n';
      continue;
    }
      
      cout << pq.top() << '\n';
      pq.pop();
    }
    else{
      pq.push(temp);
    }
  }

  return 0;
}

