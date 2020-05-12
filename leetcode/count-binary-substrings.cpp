// Runtime: 84 ms, faster than 6.13% of C++ online submissions for Count Binary Substrings.
// Memory Usage: 20.3 MB, less than 25.00% of C++ online submissions for Count Binary Substrings.

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int length = s.length();
        vector<int> countVec;
        int count = 0;
        int i = 0;
        while (true) {
            ++count;

            if (i == length - 1) {
                for (int j = i - count; j < i; ++j) countVec.push_back(count);
                break;
            }
            if (s[i] != s[i + 1]) {
                for (int j = i - count; j < i; ++j) countVec.push_back(count);
                count = 0;
            }

            i++;
        }

        int resultCnt = 0;
        for (int i = 0; i < length - 1; ++i) {
            if (s[i] != s[i + 1]) {
                resultCnt += min(countVec[i], countVec[i + 1]);
            }
        }

        return resultCnt;
    }
};