#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, k;
  cin >> n >> k;

  queue<int> q;
  for(int i = 1; i <=n;++i)
    q.push(i);

  cout << "<";
  int cnt = 0;
  while(!q.empty()){
    int n = q.front();
    q.pop();
    cnt++;
    if(cnt == k){
      cout << n;
      if(q.empty() != true)
        cout << ", ";
      cnt = 0;
    }
    else{
      q.push(n);
    } 
  }

  cout << ">";

  

}
