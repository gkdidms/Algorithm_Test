#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  queue<int> q;
  for (int i = 1; i <= n; ++i){
    q.push(i);
  }

  while(!q.empty()){
    if(q.size() == 1)
      break;
    
    q.pop();
    if(!q.empty()){
      int top = q.front();
      q.pop();
      q.push(top);
    }
  }
  cout << q.front();

}
