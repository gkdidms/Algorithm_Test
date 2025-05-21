#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll long long

using namespace std;

int main() {
  format;

  int n, l;
  cin >> n >> l;

  deque<pair<int, int>> dq;
  for (int i = 1; i <= n; ++i)
    {
      int num;
      cin >> num;

      
      while(!dq.empty() && dq.front().second <= i - l)
        dq.pop_front();

      while(!dq.empty() && dq.back().first > num)
        dq.pop_back();

      dq.push_back({num, i});

      cout << dq.front().first << " ";
    }

  
  

  return 0;
}

