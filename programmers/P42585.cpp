#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    stack<char> s;
    int count = 0;
    for (int i = 0; i < arrangement.length(); ++i) {
        if (arrangement[i] == '(') {
            s.push(arrangement[i]);
        }
        else {
            s.pop();
            if (arrangement[i-1] == '(') {
                count += s.size();
            }
            else {
                ++count;
            }
        }
    }

    return count;
}