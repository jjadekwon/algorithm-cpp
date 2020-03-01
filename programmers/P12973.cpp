#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stack;
    stack.push(s[0]);

    int idx = 1;
    while (idx < s.length()) {
        if (!stack.empty() && stack.top() == s[idx]) {
            stack.pop();
        }
        else {
            stack.push(s[idx]);
        }

        idx++;
    }

    if (stack.empty()) return 1;

    return 0;
}
