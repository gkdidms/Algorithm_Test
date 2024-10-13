#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//이동할 네 방향 정의
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

string bfs(int x, int y, int n, int m, vector<vector<string>>& map)
{
    // 큐 정의
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    //큐가 빌 때까지 반복
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        // 현재 위치에서 네 방향으로의 위치 확인
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            //미로찾기 공간을 벗어난 경우
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            //벽인 경우 무시
            if (map[nx][ny] == "0")
                continue;

            //해당 노드를 처음 방문하는 경우에만 최단 거리 기록
            if (map[nx][ny] == "1")
            {
                map[nx][ny] = to_string(stoi(map[xx][yy]) + 1); // 해당 노드에 현재 노드 + 1을 하여 최소 거리 기록
                q.push(make_pair(nx, ny));
            }
        }
    }

    return map[n - 1][m - 1];

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<string>> map(n, vector<string>(m));

    for (int i = 0; i < n; i++)
    {
        string str = "";
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = str[j];
        }
    }

    cout << bfs(0, 0, n, m, map);

}
