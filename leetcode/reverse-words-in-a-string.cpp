// Runtime: 16 ms, faster than 25.09% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 64.6 MB, less than 29.73% of C++ online submissions for Reverse Words in a String.

#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();

        string result = "";
        int i = -1;
        while (true) {
            while (s[++i] == ' ');
            if (i >= length) break;

            int j = i;
            while (true) {
                if (j == length) break;
                if (s[++j] == ' ') break;
            }

            result = s.substr(i, j - i) + " " + result;

            if (j >= length) break;

            i = j;
        }

        if (result.length() > 0) result.pop_back();
        return result;
    }
};