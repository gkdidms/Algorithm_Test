#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> In;
vector<vector<int>> Out;
vector<int> visible;
vector<int> answer;

void check(int start){  
	queue<int> q;  
	q.push(start);  
	bool isvisted = false;   //시작점을 방문 했는지
	while(!q.empty()){  
		int now = q.front();  
		q.pop();  
        
		if(now == start && isvisted){  
			answer[1]++;  
			return;  
		}  
  
		if(Out[now].size() >= 2){  
			answer[3]++;  
			return;  
		}  
  
		for(int i=0; i< Out[now].size(); i++){  
			q.push(Out[now][i]);  
		}	  
		isvisted = true;  
	}  
	answer[2]++;  
	return;  
}  

vector<int> solution(vector<vector<int>> edges) {
    answer.resize(4);
    Out.resize(1000001);
    In.resize(1000001);
    visible.resize(1000001);
    
    for (auto egde : edges)
    {
        Out[egde[0]].push_back(egde[1]);
        In[egde[1]]++;
    }
    
    //루트 노트 확인
    for (int i = 1; i <= Out.size(); ++i)
    {
        if (Out[i].size() >= 2 && In[i] == 0)
        {
            answer[0] = i;
        }
    }
    
    //그래프 모양 확인하기
    for (auto a : Out[answer[0]])
        check(a);
    
    return answer;
}