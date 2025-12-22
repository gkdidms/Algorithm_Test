#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m;
vector<string> arr;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int answer = 0;
void dfs(int x, int y){
  vector<vector<bool>> visible(n, vector<bool>(m));
  queue<pair<int, int>> q;
  q.push({x, y});
  visible[x][y] = true;

  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    for(int i = 0; i < 4; ++i){
      int nx = dx[i] + cur.first;
      int ny = dy[i] + cur.second;

      if(nx < 0 || nx >= n || ny < 0 || ny >= m || visible[nx][ny] == true || arr[nx][ny] == 'X') continue;

      if(arr[nx][ny] == 'P') answer++;

      visible[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  
}

int main() {
  format;

  cin >> n >> m;
  arr.resize(n);

  pair<int, int> start;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];

    for(int j = 0; j < m; ++j){
      if(arr[i][j] == 'I'){
        start = {i, j};
        break;
      }
    }
  }

  dfs(start.first, start.second);

  if (answer == 0) cout << "TT";
  else
    cout << answer;

  

}
