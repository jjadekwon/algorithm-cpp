// Runtime: 60 ms, faster than 29.86% of C++ online submissions for K-diff Pairs in an Array.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for K-diff Pairs in an Array.

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 1;
        set<pair<int, int> > set;
        while (i < nums.size() && j < nums.size()) {
            if (i == j) {
                ++j;
                continue;
            }

            if (nums[j] - nums[i] == k) {
                set.insert(make_pair(nums[i], nums[j]));
                ++i;
                ++j;
            }
            else if (nums[j] - nums[i] < k) {
                ++j;
            }
            else {
                ++i;
            }
        }

        return set.size();
    }
};