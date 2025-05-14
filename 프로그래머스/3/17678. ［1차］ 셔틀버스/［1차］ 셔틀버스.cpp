#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<int> times(timetable.size());
    
    for (int i = 0; i < timetable.size(); ++i)
    {
        int hour = stoi(timetable[i].substr(0, 2));
        int minute = stoi(timetable[i].substr(3, 5));
        times[i] = hour * 60 + minute;
    }
    
    sort(times.begin(), times.end());
    
    int bus = 540;
    int idx = 0;
    int anw = 0;
    
    for (int i = 1; i <= n; ++i, bus += t)
    {
        int cnt = 0;
        
        for (int j = idx; j < times.size(); ++j)
        {
            if (times[j] <= bus)
            {
                idx++;
                cnt++;
                if (cnt == m) break;
            }
            else break;
        }
        
        if (i == n)
        {
            if (cnt == m) anw = times[idx - 1] - 1;
            else anw = bus;
        }
    }
    
    int hh = anw / 60;
    int mm = anw % 60;
    
    char a = hh / 10 + '0';
    char b = hh % 10 + '0';
    char c = mm / 10 + '0';
    char d = mm % 10 + '0';
    
    answer += a;
    answer += b;
    answer += ':';
    answer += c;
    answer += d;
    return answer;
}