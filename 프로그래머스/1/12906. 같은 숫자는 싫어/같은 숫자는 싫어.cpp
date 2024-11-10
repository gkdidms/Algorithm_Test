#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int preInt = -1;
    for(auto a : arr)
    {
        if (a != preInt)
            answer.push_back(a);
            
        preInt = a;
    }

    return answer;
}