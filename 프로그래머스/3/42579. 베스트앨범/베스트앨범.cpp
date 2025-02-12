#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, vector<pair<int, int>>> m;
    vector<pair<string, int>> score;
    for (int i = 0; i < genres.size(); ++i)
    {
        m[genres[i]].push_back({i, plays[i]});
        sort(m[genres[i]].begin(), m[genres[i]].end(), [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });
        
        bool isSuccess = false;
        for (int j = 0; j < score.size(); ++j)
        {
            if (score[j].first == genres[i])
            {
                score[j].second += plays[i];
                isSuccess = true;
                break;
            }
        }
        
        if (isSuccess == false)
            score.push_back({genres[i], plays[i]});
    }
    
    sort(score.begin(), score.end(), [](pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
    });
    
    for (auto a : score)
    {
        answer.push_back(m[a.first][0].first);
        if (m[a.first].size() > 1)
            answer.push_back(m[a.first][1].first);  
    }
    
    
    return answer;
}