#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.length();
    bool *check = new bool[n];
    for (int i = 0; i < n; i++) {
        if (name[i] == 'A') check[i] = true;
        else check[i] = false;
    }
    
    int idx = 0;
    while (true) {
        if (name[idx] != 'A') {
            int min = name[idx] - 'A' < 'Z' - name[idx] + 1 ? name[idx] - 'A' : 'Z' - name[idx] + 1;
            answer += min;
            check[idx] = true;
        }
        
        bool finish = true;
        for (int i = 0; i < n; i++) {
            if (check[i] == false) {
                finish = false;
                break;
            }
        }
        
        if (finish) break;
        
        // 왼쪽 이동
        int move_left = idx;
        int move_count_left = 0;
        while (true) {
            move_count_left++;
            if (--move_left < 0) move_left = n - 1;
            
            if (!check[move_left]) break;
        }
        // 오른쪽 이동
        int move_right = idx;
        int move_count_right = 0;
        while (true) {
            move_count_right++;
            if (++move_right >= n) move_right = 0;
            
            if (!check[move_right]) break;
        }
        
        if (move_count_left < move_count_right) {
            idx = move_left;
            answer += move_count_left;
        }
        else {
            idx = move_right;
            answer += move_count_right;
        }
    }
    
    delete[] check;
    return answer;
}