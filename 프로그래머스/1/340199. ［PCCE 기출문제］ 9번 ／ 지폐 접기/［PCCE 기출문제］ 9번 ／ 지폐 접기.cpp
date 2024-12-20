#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(true)
    {
        if ((wallet[0] >= bill[0] && wallet[1] >= bill[1])
           || (wallet[0] >= bill[1] && wallet[1] >= bill[0]))
            break;
        
        answer++;
        
        //항상 길이가 긴 쪽을 반으로 접는다
        if (bill[0] > bill[1])
            bill[0] /= 2;
        else
            bill[1] /= 2;
    }
    
    return answer;
}