#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [](vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) return a[1] < b[1];
        
        return a[0] < b[0];
    });
    
    int up, down, tempUp, tempDown;
    for (int i = 0; i < data.size(); ++i)
    {
        up = pow(2, 31) -1, down = 0;
        tempUp = up, tempDown = down;
        for (int j = i + 1; j < data.size(); ++j)
        {
            if (data[j - 1][0] != data[j][0]) 
            {
                //높이가 변하는 경우 업데이트
                up = tempUp;
                down = tempDown;
            }
            
            if (data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
            else if (data[j][1] > data[i][1])
            {
                if (up >= data[j][1]) answer++;
                tempUp = min(tempUp, data[j][1]);
            }
            else if (data[j][1] < data[i][1])
            {
                if (down <= data[j][1]) answer++;
                tempDown = max(tempDown, data[j][1]);
            }
        }
    }
    
    return answer;
}