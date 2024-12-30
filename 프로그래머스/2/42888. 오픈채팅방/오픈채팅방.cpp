#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

map<string, string> m; 
vector<pair<string, string>> action; // action, id

void Change(string id, string name)
{
    auto iter = m.find(id);
    
    if (iter != m.end())
    {
        iter->second = name;
    }
}

void Enter(string a, string id, string name)
{
    m[id] = name;
    action.push_back({a, id});
}

void Leave(string a, string id)
{
    action.push_back({a, id});
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(auto a : record)
    {
        vector<string> v;
        stringstream ss(a);
        string str;
        
        while(ss >> str)
        {
            v.push_back(str);
        }
        
        if (v[0] == "Enter")
        {
            Enter(v[0], v[1], v[2]);
        }
        else if (v[0] == "Leave")
        {
            Leave(v[0], v[1]);
        }
        else if (v[0] == "Change")
        {
            Change(v[1], v[2]);
        }
    }
    
    for (auto a : action)
    {
        if (a.first == "Enter")
        {
            auto iter = m.find(a.second);
            answer.push_back(iter->second + "님이 들어왔습니다.");
        }
        else if (a.first == "Leave")
        {
            auto iter = m.find(a.second);
            answer.push_back(iter->second + "님이 나갔습니다.");
        }
    }
    
    return answer;
}