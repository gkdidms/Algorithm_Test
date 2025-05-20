#include <string>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

long long solution(int r1, int r2) {
    ll answer = 0;
    
    ll R1 = 0, R2 = 0;
    
    //축을 제외한 한 사분면에 존재할 수 잇는 정수 좌표의 수 구하기
    for (int x = 1; x < r2; ++x)
    {
        //큰 원 내부에서 x좌표가 x일때 존재할 수 있는 정수 좌표의 수
        R2 = floor(sqrt(pow(r2, 2) - pow(x, 2))); 
        
        if (x < r1)
            //작은 원 내부에서 x좌표가 x일때 존재할 수 있는 정수 좌표의 수
            R1 = ceil(sqrt(pow(r1, 2) - pow(x, 2)));
        else R1 = 1;
        
        answer += R2 - R1 + 1;
    }
    
    // 4 * (1사분면 좌표 수 + 한 축 위에 존재할 수 있는 큰 원과 작은 원 사이의 좌표 수)
    answer = 4 * (answer + r2 - r1 + 1);
    
    return answer;
}