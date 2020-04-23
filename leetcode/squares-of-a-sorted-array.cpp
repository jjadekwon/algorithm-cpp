// Runtime: 152 ms, faster than 37.73% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Squares of a Sorted Array.

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            A[i] *= A[i];
        }

        sort(A.begin(), A.end());

        return A;
    }
};