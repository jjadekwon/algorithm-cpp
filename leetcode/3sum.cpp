// Runtime: 100 ms, faster than 73.13% of C++ online submissions for 3Sum.
// Memory Usage: 23.5 MB, less than 7.65% of C++ online submissions for 3Sum.

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > result; 
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;

            int l = i + 1;
            int r = size - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) ++l;
                else if (sum > 0) --r;
                else {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    result.push_back(v);

                    while (l < r && nums[l] == nums[l+1] && nums[r] == nums[r-1]) {
                        ++l; --r;
                    }
                    ++l; --r;
                }
            }
        }

        return result;
    }
};