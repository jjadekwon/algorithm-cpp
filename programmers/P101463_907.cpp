#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    if (s.length() != 4 && s.length() != 6) return false;
    
    for (char c : s) {
        cout << c - '0'<< endl;
        if (c - '0' > 9) return false;
    }
    
    return true;
}