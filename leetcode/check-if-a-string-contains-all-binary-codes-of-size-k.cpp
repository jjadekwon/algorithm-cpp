// Runtime: 1260 ms, faster than 21.52% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
// Memory Usage: 25.9 MB, less than 79.30% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.

// unordered_set
// Runtime: 488 ms, faster than 73.37% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
// Memory Usage: 25.7 MB, less than 80.94% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.

#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int length = s.length();
        int count = pow(2, k);
        
        if (length <= k) return false;

        unordered_set<string> set;
        for (int i = 0; i <= length - k; ++i) {
            set.insert(s.substr(i, k));
        }

        if (set.size() == count) return true;

        return false;
    }
};