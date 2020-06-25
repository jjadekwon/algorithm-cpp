// Runtime: 4 ms, faster than 82.40% of C++ online submissions for First Missing Positive.
// Memory Usage: 9.8 MB, less than 52.01% of C++ online submissions for First Missing Positive.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) continue;
            if (nums[i] > n) return n;
            if (nums[i] < n) continue;
            ++n;
        }

        return n;
    }
};