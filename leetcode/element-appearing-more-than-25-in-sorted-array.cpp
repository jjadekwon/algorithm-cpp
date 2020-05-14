// Runtime: 24 ms, faster than 45.25% of C++ online submissions for Element Appearing More Than 25% In Sorted Array.
// Memory Usage: 12.5 MB, less than 100.00% of C++ online submissions for Element Appearing More Than 25% In Sorted Array.

#include <vector>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        int count = size / 4;
        for (int i = 0; i < size; ++i) {
            if (arr[i] == arr[i + count]) return arr[i];
        }

        return 0;
    }
};