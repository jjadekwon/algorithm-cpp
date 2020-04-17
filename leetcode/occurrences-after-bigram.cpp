// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Occurrences After Bigram.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Occurrences After Bigram.

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);

        vector<string> strings;
        string temp;
        while (getline(ss, temp, ' ')) {
            strings.push_back(temp);
        }

        vector<string> result;
        for (int i = 0; i < strings.size() - 2; ++i) {
            if (strings[i] == first && strings[i + 1] == second) {
                result.push_back(strings[i + 2]);
            }
        }

        return result;
    }
};