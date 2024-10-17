//이것이 코딩 테스트다 259p 미래도시
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#define INF int(1e9)

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, m = 0;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    //자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
            if (i == j) graph[i][j] = 0;
    }

    //간선에 대한 값을 받기
    for (int _ = 0; _ < m; ++_)
    {
        int i = 0, j = 0;
        cin >> i >> j;
        graph[i][j] = 1;
        graph[j][i] = 1;
    }

    // a는 k번 회사를 방문한 뒤 x번 회사로 가는 것이 목표다
    int x = 0, k = 0;
    cin >> x >> k;

    //점화식에 따라 플로이드 워셜 알고리즘을 수행
    for (int c = 1; c < n + 1 ; ++c)
    {
        for (int a = 1; a < n + 1; ++a)
        {
            for (int b = 1; b < n + 1; ++b)
                graph[a][b] = min(graph[a][b], graph[a][c] + graph[c][b]);
        }
    }

    if (graph[1][k] == INF || graph[k][x] == INF)
        cout << "-1" << endl;
    else
        cout << graph[1][k] + graph[k][x] << endl;

}