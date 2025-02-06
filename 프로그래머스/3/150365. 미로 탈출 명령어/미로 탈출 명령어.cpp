#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node{
    string str;
    int cnt, x, y;
};

struct compare{
    bool operator()(node x, node y){
        return x.str > y.str;
    }
};

string bfs(int n, int m, int x, int y, int r, int c, int k)
{
    vector<vector<vector<bool>>> visible(k + 1, vector<vector<bool>>(n + 1, vector<bool>(m+ 1)));
    priority_queue<node, vector<node>, compare> pq;
    pq.push({"", 0, x, y});
    visible[0][x][y] = true;
    
    while(!pq.empty())
    {
        string str = pq.top().str;
        int cnt = pq.top().cnt;
        pair<int, int> pos = {pq.top().x, pq.top().y};
        pq.pop();
        
        if (pos.first == r && pos.second == c && cnt == k)
        {
            return str;
        }
        if ((abs(pos.first - r) + abs(pos.second - c)) % 2 != 0 && (k - cnt) % 2 == 0) continue;
        
        for (int i = 0; i < 4; ++i)
        {
            string anw = str;
            int nx = pos.first;
            int ny = pos.second;
            if (i == 0)
            {
                //아래쪽으로 한 칸 이동
                anw += "d";
                nx += 1;
            }
            else if (i == 1)
            {
                //왼쪽으로 한 칸 이동
                anw += "l";
                ny -= 1;

            }
            else if (i == 2)
            {
                //오른쪽으로 한 칸 이동
                anw += "r";
                ny += 1;
            }
            else if (i == 3)
            {
                //위쪽으로 한 칸 이동
                anw += "u";
                nx -= 1;
            }
            
            if (nx < 1 || nx > n || ny < 1 || ny > m || cnt > k || visible[cnt][nx][ny]) continue;

            visible[cnt][nx][ny] = true;
            pq.push({anw, cnt + 1, nx, ny});
        }
    }
    
    return "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    answer = bfs(n, m, x, y, r, c, k);
    return answer;
}