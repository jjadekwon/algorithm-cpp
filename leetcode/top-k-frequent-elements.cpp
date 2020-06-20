// Runtime: 44 ms, faster than 31.36% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 14 MB, less than 62.19% of C++ online submissions for Top K Frequent Elements.

#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) m[nums[i]]++;

        priority_queue<pair<int, int> > pq;
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};