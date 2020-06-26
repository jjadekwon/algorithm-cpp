// Runtime: 28 ms, faster than 18.18% of C++ online submissions for Palindrome Number.
// Memory Usage: 5.9 MB, less than 78.97% of C++ online submissions for Palindrome Number.

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        string s = to_string(x);
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;

            ++l; --r;
        }

        return true;
    }
};