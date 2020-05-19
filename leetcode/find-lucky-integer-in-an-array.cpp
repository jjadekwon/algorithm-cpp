// map
// Runtime: 16 ms, faster than 37.18% of C++ online submissions for Find Lucky Integer in an Array.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Find Lucky Integer in an Array.

// unordered_map
// Runtime: 4 ms, faster than 99.81% of C++ online submissions for Find Lucky Integer in an Array.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Find Lucky Integer in an Array.

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> cntMap;
        for (int i = 0; i < arr.size(); ++i) {
            cntMap[arr[i]]++;
        }

        int max = -1;
        for (auto m : cntMap) {
            if (m.first == m.second && max < m.first) {
                max = m.first;
            }
        }

        return max;
    }
};