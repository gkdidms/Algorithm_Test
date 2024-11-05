#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> table;
    for (auto a : tangerine)
    {
        table[a]++;
    }
    
    vector<pair<int, int>> vecTable(table.begin(), table.end());
    
    //내림차순으로 정렬
    sort(vecTable.begin(), vecTable.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
    });
    
    for (auto temp : vecTable)
    {
        k -= temp.second;
        ++answer;
        if (k <= 0)
            return answer;
    }
    
    return answer;
}