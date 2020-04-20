// Runtime: 68 ms, faster than 8.75% of C++ online submissions for Ransom Note.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Ransom Note.

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> map;
        for (char c : magazine) map[c]++;

        for (char c : ransomNote) {
            if (map.count(c) == 0) return false;
            if (--map[c] < 0) return false;
        }

        return true;
    }
};