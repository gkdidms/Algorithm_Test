#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<int> server_q;
    queue<int> clear_q;
    int allServer = 0;
    for (int i = 0; i < 24; ++i)
    {
        if (clear_q.size() > 0 && clear_q.front() == i)
        {
            if (server_q.size() > 0)
            {            
                int server = server_q.front();
                server_q.pop();
                clear_q.pop();
                allServer -= server; 
            }
        }
        
        if (players[i] >= m)
        {
            if (players[i] / m > allServer)
            {
                int temp = players[i] / m - allServer;
                answer += temp;
                server_q.push({temp});
                clear_q.push({i + k});
                
                allServer += temp;
            }
        }
    }
    
    return answer;
}