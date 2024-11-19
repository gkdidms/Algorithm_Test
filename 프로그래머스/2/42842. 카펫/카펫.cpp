#include <string>
#include <vector>
#include <cmath>

#define INF 1000000
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    //가로의 길이는 세로의 길이와 같거나, 세로 길이보다 길다.
    int min = sqrt(brown + yellow); // 최소값
    
    for (int i = min; i < INF; ++i)
    {
        for (int j = 3; j <= min; ++j)
        {
            int all = i * j;
            int b = (i + j) * 2 - 4;
            int y = all - b;
            
            if (b == brown && y == yellow)
            {
                answer[0] = i;
                answer[1] = j;
                break;
            }
        }
    }
    
    return answer;
}