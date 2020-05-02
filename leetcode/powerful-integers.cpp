// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Powerful Integers.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Powerful Integers.

#include <vector>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int, less<int> > set;

        bool check = false;
        for (int i = 0; ; ++i) {
            int powX = pow(x, i);
            if (powX > bound) break;

            for (int j = 0; ; ++j) {
                int powY = pow(y, j);
                int sum = powX + powY;
                if (sum > bound) break;
                set.insert(sum);

                if (y == 1) break;
            }

            if (x == 1) break;
        }

        vector<int> result;
        for (int i : set) result.push_back(i);
        return result;
    }
};