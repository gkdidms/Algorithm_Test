#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    //시작 시간 정렬
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b){
        return a[1] < b[1];
    });
    
    int endTime = -30001;
    for (int i = 0; i < routes.size(); ++i)
    {
        if (endTime < routes[i][0])
        {
            endTime = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}