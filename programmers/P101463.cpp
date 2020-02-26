#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int count_p = 0;
    int count_y = 0;
    
    for (int i = 0; i < s.length(); i++) {
        char upper = toupper(s[i]);
        if (upper == 'P') count_p++;
        else if (upper == 'Y') count_y++;
    }
    
    if (count_p == count_y) return true;
    
    return false;
}