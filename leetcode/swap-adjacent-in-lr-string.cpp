// Runtime: 12 ms, faster than 35.03% of C++ online submissions for Swap Adjacent in LR String.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Swap Adjacent in LR String.

#include <string>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) return false;

        string s = start;
        string e = end;
        s.erase(remove(s.begin(), s.end(), 'X'), s.end());
        e.erase(remove(e.begin(), e.end(), 'X'), e.end());
        if (s != e) return false;

        int length = start.length();
        int j = 0;
        for (int i = 0; i < length; ++i) {
            if (start[i] == 'L') {
                while (end[j++] != 'L');
                if (i < j-1) return false;
            }
        }

        j = 0;
        for (int i = 0; i < length; ++i) {
            if (start[i] == 'R') {
                while (end[j++] != 'R');
                if (i > j-1) return false;
            }
        }

        return true;
    }
};