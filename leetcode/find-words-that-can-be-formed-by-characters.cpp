// Runtime: 260 ms, faster than 21.45% of C++ online submissions for Find Words That Can Be Formed by Characters.
// Memory Usage: 57.4 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.

#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m;
        for (int i = 0; i < chars.length(); ++i) m[chars[i]]++;

        int length = 0;
        for (int i = 0; i < words.size(); ++i) {
            map<char, int> copyMap = m;
            bool check = true;
            for (int j = 0; j < words[i].size(); ++j) {
                if (--copyMap[words[i][j]] < 0) {
                    check = false;
                    break;
                } 
            }

            if (check) {
                length += words[i].size();
            }
        }

        return length;
    }
};