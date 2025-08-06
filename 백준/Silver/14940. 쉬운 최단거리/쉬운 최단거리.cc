#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<bool>> visibility;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool CheckVisible(){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      if (visibility[i][j] == false)
        return false;
    }
  }



  return true;
}

void bfs(pair<int, int> pos){

  queue<pair<int, int>> q;
  q.push(pos);

  while(!q.empty()){
    pair<int, int> cur = q.front();
    q.pop();

    if (CheckVisible() == true) return;

    for (int i = 0; i < 4; ++i){
          int nx = cur.first + dx[i];
    int ny = cur.second + dy[i];

    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visibility[nx][ny] || map[nx][ny] == 0) continue;

    visibility[nx][ny] = true;

    map[nx][ny] = map[cur.first][cur.second] + 1;
      q.push({nx, ny});
    }
  }
}

int main() {
  format;

  cin >> n >> m;
  map.resize(n, vector<int>(m));
  visibility.resize(n, vector<bool>(m));
  
  pair<int, int> startPos;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> map[i][j];

      if (map[i][j] == 2)
        startPos = {i, j};
    }
  }

  map[startPos.first][startPos.second] = 0;
  visibility[startPos.first][startPos.second] = true;
  
  bfs(startPos);

  for(int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      if (visibility[i][j] == false && map[i][j] == 1)
        cout << -1 << " ";
      else
        cout << map[i][j] << " ";
    }
    cout << '\n';
  }
}
