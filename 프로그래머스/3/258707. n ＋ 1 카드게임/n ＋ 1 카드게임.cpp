#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Pair
{
    int cost;
    pair<int, int> pairCard;
    
    bool operator<(const Pair a) const
    {
        return cost > a.cost;
    }
};

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    int n = cards.size();
    int idx = 0;
    
    unordered_map<int, bool> hand;
    unordered_map<int, int> cardCost;
    priority_queue<Pair> pq;
    
    for (idx = 0; idx < n / 3; ++idx)
    {
        hand[cards[idx]] = true;
        
        if (hand[n + 1 - cards[idx]])
        {
            pq.push({0, {cards[idx], n + 1 - cards[idx]}});
        }
    }
    
    for ( ; idx < n; ++idx)
    {
        hand[cards[idx]] = true;
        cardCost[cards[idx]] += 1;
        
        if (hand[n + 1 - cards[idx]])
        {
            pq.push({cardCost[cards[idx]] + cardCost[n + 1 - cards[idx]], {cards[idx], n + 1 - cards[idx]}});
        }
        
        if (idx % 2 == 1)
        {
            if (!pq.empty())
            {
                Pair temp = pq.top();
                pq.pop();
                
                if (temp.cost > coin)  break;
                
                coin -= temp.cost;
                answer += 1;
            }
            else
                break;
        }
    }
        
    
    
    return answer;
}