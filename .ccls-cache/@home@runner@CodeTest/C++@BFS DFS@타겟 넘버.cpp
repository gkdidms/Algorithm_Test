#include <string>
#include <vector>

using namespace std;

int dfs(int i, int total, int num, vector<int> numbers, int target)
{
    int newTotal = i + total;
    int n = 0;
    int newNum = num + 1;

    if (newNum == numbers.size())
    {
        if (target == newTotal)
            return 1;

        return 0;
    }

    n += dfs(numbers[newNum], newTotal, newNum, numbers, target);
    n += dfs(numbers[newNum] * -1, newTotal, newNum, numbers, target);

    return n;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer += dfs(numbers[0], 0, 0, numbers, target);
    answer += dfs(numbers[0] * -1, 0, 0, numbers, target);

    return answer;
}