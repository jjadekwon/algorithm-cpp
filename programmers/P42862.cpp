#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    int count = lost.size();
    // 같은 학생 제거
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost[i] = reserve[j] = -1;
                count--;
                break;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == -1) continue;
        
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == -1) continue;
            
            if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) {
                count--;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    answer -= count;
    
    return answer;
}