#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<string> answer;
map<string, vector<string>> ticket;
 map<string, vector<bool>> visible;

bool check_all()
{
    for (auto iter = visible.begin(); iter != visible.end(); ++iter)
    {
        bool isSuccess = true;
        for (auto a : iter->second)
            if (a == false) return false;
    }
    
    return true;
}

bool check_value(string node)
{
    for (auto a : visible[node])
    {
        if (a == false)
            return false;
    }
    
    return true;
}

bool dfs(vector<string>& v, string node)
{  
    bool isSuccess = check_all();
    if (!isSuccess && (ticket.find(node) == ticket.end() || check_value(node)))
    {
        return false;
    }
    if (isSuccess)
    {
        answer.insert(answer.end(), v.begin(), v.end());
        return true;
    }
        
    
    for (int i = 0; i < ticket[node].size(); ++i)
    {
        if (visible[node][i] == false)
        {
            vector<string> copy(v);
            visible[node][i] = true;
            copy.push_back(ticket[node][i]);
            if (!dfs(copy, ticket[node][i]))
                visible[node][i] = false;
            else return true;
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    map<string, vector<string>> m;
   
    
    for (auto a : tickets)
    {
        m[a[0]].push_back(a[1]);
    }
    
    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        sort(iter->second.begin(), iter->second.end());
        visible[iter->first].resize(iter->second.size());
    }
    
    ticket = m;
    vector<string> v;
    v.push_back("ICN");
    dfs(v, "ICN");
    
    return answer;
}