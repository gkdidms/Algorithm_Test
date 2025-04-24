#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct timeline {
  int h, m;
    double s;
};

int solution(vector<string> lines) {
    int answer = 1;
    
    vector<vector<timeline>> timelines(lines.size(), vector<timeline>(2));
    
    int first = stoi(lines[0].substr(11,13));
    int second = stoi(lines[0].substr(14,16));
    for (int i = 0; i < lines.size(); ++i)
    {
        int h = stoi(lines[i].substr(11,13));
        int temp = h - first;
        int m = stoi(lines[i].substr(14,16));
        int temp2 = m + (60 * h) - second;
        double s = stod(lines[i].substr(17,23)) + (60.0 * temp2);
        double t = stod(lines[i].substr(24,lines[i].size() - 1));
        
        timelines[i][0] = timeline{h, m, s - t + 0.001};
        timelines[i][1] = timeline{h, m, s};
    }
    
    sort(timelines.begin(), timelines.end(), [](const auto& a, const auto& b) {
        if (a[0].h == b[0].h)
        {
            if (a[0].m == b[0].m)
                return a[0].s < b[0].s;
            return a[0].m < b[0].m;
        }
        return a[0].h < b[0].h;
    });
    
    priority_queue<double, vector<double>, greater<double>> pq;
    pq.push(timelines[0][1].s);
    
    for (int i = 1; i < timelines.size(); ++i)
    {
        if (timelines[i][0].s - pq.top() >= 1.0)
        {
            pq.pop(); 
        }
            
        pq.push(timelines[i][1].s);
        
        int size = pq.size();
        answer = max(answer, size);
    }
    
    return answer;
}