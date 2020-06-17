// Runtime: 68 ms, faster than 42.03% of C++ online submissions for Valid Mountain Array.
// Memory Usage: 22.4 MB, less than 73.37% of C++ online submissions for Valid Mountain Array.

#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;

        if (A[0] > A[1]) return false;

        bool decreasing = false;
        for (int i = 1; i < A.size() - 1; ++i) {
            if (A[i] == A[i + 1]) return false;
            
            if (A[i] > A[i + 1]) {
                decreasing = true;
            }

            if (decreasing && A[i] <= A[i + 1]) return false;
        }

        return decreasing ? true : false;
    }
};