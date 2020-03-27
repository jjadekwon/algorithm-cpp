// Runtime: 28 ms, faster than 95.04% of C++ online submissions for Non-decreasing Array.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Non-decreasing Array.

#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                    count++;
                }
                else {
                    nums[i] = nums[i + 1];
                    count++;
                }
            }

            if (count > 1) return false;
        }

        return true;
    }
};