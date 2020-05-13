// Runtime: 20 ms, faster than 28.75% of C++ online submissions for Range Addition II.
// Memory Usage: 11.3 MB, less than 100.00% of C++ online submissions for Range Addition II.

#include <vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int> >& ops) {
        int a = m;
        int b = n;
        int size = ops.size();
        for (int i = 0; i < size; ++i) {
            a = min(a, ops[i][0]);
            b = min(b, ops[i][1]);
        }

        return a * b;
    }
};