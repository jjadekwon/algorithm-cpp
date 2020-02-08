#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    priority_queue<int, vector<int>, less<int>> queue;
    
    int answer = 0;
    int idx = 0;
    while (stock < k) {
        for (int i = idx; i < dates.size(); i++) {
            if (dates[i] <= stock) {
                queue.push(supplies[i]);
                idx++;
            }
        }
        
        stock += queue.top();
        queue.pop();
        answer++;
    }
    
    return answer;
}