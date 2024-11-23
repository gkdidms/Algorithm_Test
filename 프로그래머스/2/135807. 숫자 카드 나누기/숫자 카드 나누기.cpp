#include <string>
#include <vector>
#include <queue>

using namespace std;

int gcd(int a, int b)
{
    while(b > 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    int anw1 = arrayA[0];
    int anw2 = arrayB[0];
    for (int i = 1; i < arrayA.size(); ++i)
    {
        anw1 = gcd(anw1, arrayA[i]);
        anw2 = gcd(anw2, arrayB[i]);
    }
    
    bool isA = true, isB = true;
    for (int i = 0; i < arrayA.size(); ++i)
    {
        if (arrayB[i] % anw1 == 0)
            isA = false;
        
        if (arrayA[i] % anw2 == 0)
            isB = false;
    }
    
    if (isA && isB) answer = max(anw1, anw2);
    else if (isA) answer = anw1;
    else if (isB) answer = anw2;
    
    return answer;
}