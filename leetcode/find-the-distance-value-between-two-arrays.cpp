// range-based for loop
// Runtime: 20 ms, faster than 33.34% of C++ online submissions for Find the Distance Value Between Two Arrays.
// Memory Usage: 13.1 MB, less than 100.00% of C++ online submissions for Find the Distance Value Between Two Arrays.

// for
// Runtime: 16 ms, faster than 45.45% of C++ online submissions for Find the Distance Value Between Two Arrays.
// Memory Usage: 13.3 MB, less than 100.00% of C++ online submissions for Find the Distance Value Between Two Arrays.

// for / int n, m = arr.size();
// Runtime: 12 ms, faster than 86.19% of C++ online submissions for Find the Distance Value Between Two Arrays.
// Memory Usage: 13.3 MB, less than 100.00% of C++ online submissions for Find the Distance Value Between Two Arrays.

#include <vector>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            bool check = true;
            for (int j = 0; j < m; ++j) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    check = false;
                    break;
                }
            }
            if (check) ++count;
        }
        
        return count;
    }
};