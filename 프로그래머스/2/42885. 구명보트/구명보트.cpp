#include <string>
#include <vector>
#include <algorithm>
#define INF int(1e9)
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<int>());
    
    int start = 0;
    int end = people.size() - 1;
    
    while(end >= start)
    {
        if (end == start)
        {
            start++;
            answer++;
            continue;
        }
        
        if (people[start] + people[end] <= limit)
        {
            start++;
            end--;
            answer++;
        }
        else
        {
            start++;
            answer++;
        }
    }
    
    return answer;
}