#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int x, int y, int n, int m, vector<vector<string>> &map) {
  if (x <= -1 || x >= n || y <= -1 || y >= m)
    return false;

  if (map[x][y] == "0") {
    map[x][y] = "1";

    dfs(x - 1, y, n, m, map);
    dfs(x + 1, y, n, m, map);
    dfs(x, y - 1, n, m, map);
    dfs(x, y + 1, n, m, map);

    return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<string>> map(n, vector<string>(m));

  for (int i = 0; i < n; i++) {
    string shr = "";
    cin >> shr;

    for (int j = 0; j < m; j++) {
      map[i][j] = shr[j];
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (dfs(i, j, n, m, map) == true)
        result++;
  }

  cout << result << endl;
}
