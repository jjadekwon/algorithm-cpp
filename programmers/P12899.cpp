#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while (true) {
        int p = n / 3;
        int q = n % 3;
        if (q == 0) {
            p--;
            q = 4;
        }
        
        answer = to_string(q) + answer;

        if (p == 0) break;
        
        n = p;
    }
    
    return answer;
}