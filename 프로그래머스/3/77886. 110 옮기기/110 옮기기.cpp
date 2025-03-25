#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    int onecnt = 0;
    int ooz = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        string ones = "";
        onecnt = 0;
        ooz = 0;
        
        for (int j = 0; j < s[i].size(); ++j)
        {
                    if (s[i][j] == '1') onecnt++;
        else
        {
            if (onecnt >= 2)
            {
                ooz++;
                onecnt -= 2;
            }
            else
            {
                for (int k = 0; k < onecnt; ++k)
                    ones.push_back('1');
                
                ones.push_back('0');
                onecnt = 0;
            }
        }
        }
        

        
        for (int k = 0; k < ooz; ++k)
        {
            ones.push_back('1');
            ones.push_back('1');
            ones.push_back('0');
        }
        for (int k = 0; k < onecnt; ++k)
            ones.push_back('1');
        
        answer.push_back(ones);
    }
    
    return answer;
}