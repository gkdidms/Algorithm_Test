#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int maxX = 0, maxY = 0;
    for (auto pos : sizes)
    {
        if (pos[0] > pos[1])
        {
            maxX = max(maxX, pos[0]);
            maxY = max(maxY, pos[1]);
        }
        else
        {
            maxX = max(maxX, pos[1]);
            maxY = max(maxY, pos[0]);
        }
    }

    answer = maxX * maxY;

    return answer;
}