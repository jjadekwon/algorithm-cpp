#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> queue(scoville.begin(), scoville.end());
    
    while (queue.top() < K) {
        if (queue.size() == 1) return -1;
        
        int first = queue.top();
        queue.pop();
        int second = queue.top();
        queue.pop();
        
        int mix = first + (second * 2);
        queue.push(mix);
        
        answer++;
    }
    
    return answer;
}