#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> Stations;

    Stations.emplace_back(0 - w);
    for(const auto& x : stations)
    {
        Stations.emplace_back(x);
    }
    Stations.emplace_back(n + w + 1);


    for(int Index = 1; Index < Stations.size(); ++Index)
    {
        int NotReachedCount = (Stations[Index] - w - 1) - (Stations[Index - 1] + w + 1) + 1;

        if(NotReachedCount <= 0)
        {
            continue;
        }

        answer += NotReachedCount / (w * 2 + 1);
        if(NotReachedCount % (w * 2 + 1) != 0)
        {
            answer += 1;
        }

    }
    
    return answer;
}