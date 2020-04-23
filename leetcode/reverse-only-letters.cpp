// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Reverse Only Letters.

#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int s = 0;
        int e = S.length() - 1;
        
        while (s < e) {
            if (!isalpha(S[s])) {
                ++s;
                continue;
            }
            if (!isalpha(S[e])) {
                --e;
                continue;
            }

            char temp = S[s];
            S[s] = S[e];
            S[e] = temp;
            ++s; --e;
        }

        return S;
    }
};