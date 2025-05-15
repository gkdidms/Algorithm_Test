#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int answer = 0;

set<string> visible;

//소수는 0, 1이 되면 안됨.
//나눠지는 수가 있으면 안됨.
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0) return false;
    }
    
    return true;
}

void dfs(string n, string numbers, vector<bool>& v)
{
    if (n.size() >= numbers.size()) return;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (v[i]) continue;
        
        string str = n + numbers[i];
        if(str == "0" || visible.find(str) != visible.end()) continue;

        if (isPrime(stoi(str))){
            visible.insert(str); // 소수라면?
            answer++;
        }
        
        v[i] = true;
        dfs(str, numbers, v);
        v[i] = false;
    }
}

int solution(string numbers) {
    
    string str = "";
    vector<bool> v(numbers.size());
    dfs(str, numbers, v);
    
    return answer;
}