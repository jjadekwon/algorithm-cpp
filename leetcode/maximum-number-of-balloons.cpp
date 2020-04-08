// Runtime: 20 ms, faster than 6.71% of C++ online submissions for Maximum Number of Balloons.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Maximum Number of Balloons.

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> map;
        for (char c : text) {
            if (map.count(c) == 0) {
                map.insert(make_pair(c, 1));
            }
            else {
                map.at(c)++;
            }
        }

        int maximum = map.count('b') == 0 ? 0 : map.at('b');
        if (maximum == 0) return 0;

        for (auto it = map.begin(); it != map.end(); it++) {
            switch (it->first) {
                case 'a': case 'n':
                    if (it->second < maximum) {
                        maximum = it->second;
                    }
                break;
                case 'l': case 'o':
                    if (it->second / 2 < maximum) {
                        maximum = it->second / 2;
                    }
                break;
            }
        }

        return maximum;
    }
};