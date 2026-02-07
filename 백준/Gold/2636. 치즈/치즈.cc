#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n, m;
vector<vector<int>> arr;
queue<pair<int, int>> q;
int answer= 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//가장자리 구하기
void bfs(){
  vector<vector<bool>> visible(n, vector<bool>(m));
  
  queue<pair<int, int>> temp;
  temp.push({0, 0});
  visible[0][0] = true;
  
  while(!temp.empty()){
    auto cur = temp.front();
    temp.pop();

    for(int i = 0; i < 4; ++i){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m || visible[nx][ny] == true || arr[nx][ny] == 1)
        continue;

      visible[nx][ny] = true;
        temp.push({nx, ny});
      if(arr[nx][ny] == 0){
        arr[nx][ny] = -1;
        q.push({nx, ny});
      }
    }
  }
}

void bfs2(){
  vector<vector<bool>> visible(n, vector<bool>(m));

  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    for(int i = 0; i < 4; ++i){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m || visible[nx][ny] == true)
        continue;

      if(arr[nx][ny] == 1){
        visible[nx][ny] = true;
         arr[nx][ny] = 0;
      }
    }
  }
}

int check(){
  int cnt = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(arr[i][j] == 1){
        cnt++;
      }
    }
  }

  if(cnt != 0){
    answer = cnt;
  }
    
  return cnt;
}

int main() {
  format;

  cin >> n >> m;

  arr.resize(n, vector<int>(m));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> arr[i][j];
    }
  }

  int time = 0;
  while(true){
    int cnt = check();
    if(cnt == 0)
      break;
    time++;
    bfs();
    bfs2();
  }

  cout << time << '\n' << answer;
  
}
