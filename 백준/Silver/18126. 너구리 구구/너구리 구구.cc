#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
typedef long long ll;

int n;
ll answer = 0;
vector<vector<pair<int, ll>>> tree;
vector<bool> visible(5001);

void dist(int start, ll len){
  answer = max(answer, len);
  if (tree[start].empty()) return;
  else {
    for(int i = 0; i < (int)tree[start].size(); ++i){
      int next = tree[start][i].first;
      int cost = tree[start][i].second;

      if (!visible[next]){
        visible[next] = true;
        dist(next, len + cost);
      }
    }
  }
}

int main() {
  cin >> n;

  tree.resize(n + 1);
  visible[1] = true;

  for (int i = 0, a, b, len; i< n -1; ++i){
    cin >> a>> b>> len;

    tree[a].push_back({b, len});
    tree[b].push_back({a, len});
  }

  dist(1, 0);
  cout << answer;
}
