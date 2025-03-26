#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string, int> roll;
    map<string, string> parent; // 자식 / 부모
    
    for (int i = 0; i < enroll.size(); ++i)
        parent[enroll[i]] = referral[i];
    
    for (int i = 0; i < seller.size(); ++i)
    {
        //판매자
        int coin = amount[i] * 100;
        string pnt = seller[i];
        
        while(true)
        {
            int temp = coin * 0.1;
            roll[pnt] += coin - temp;
            coin = temp;
            
            if (pnt == "-" || coin == 0) break;
            else pnt = parent[pnt];
        }
    }
    
    for (auto str : enroll)
    {
        answer.push_back(roll[str]);
    }
    
    return answer;
}