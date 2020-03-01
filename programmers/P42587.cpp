#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer;
    for (int p : priorities) printer.push(p);
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    int idx = 0;
    while (true) {
        int front = printer.front();
        printer.pop();
        if (front < priorities[idx]) {
            printer.push(front);
        }
        else {
            idx++;
            if (location == 0) return idx;
        }
        
        location--;
        if (location < 0) location = printer.size() - 1;
    }
    
    return 0;
}