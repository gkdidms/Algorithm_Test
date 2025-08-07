#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m;
vector<int> v;
set<vector<int>> s;

void dfs(int cnt, vector<int>& list){

  if ((int)list.size() == m){
      for (auto a : list){
        cout << a << " ";
      }
      cout << '\n';
    return;
  }

  for (int i = cnt; i < (int)v.size(); ++i){
    list.push_back(v[i]);
    if(s.find(list) == s.end()){
      s.insert(list);
       dfs(i, list);
    }
    list.pop_back();
  }
}

int main() {
  format;

  cin >> n >> m;

  v.resize(n);
  for (int i = 0; i < n; ++i){
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  vector<int> list;
  dfs(0, list);
  
}
