// Runtime: 8 ms, faster than 54.56% of C++ online submissions for Positions of Large Groups.
// Memory Usage: 7.5 MB, less than 28.10% of C++ online submissions for Positions of Large Groups.

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > largeGroupPositions(string S) {
        vector<vector<int> > indices;
        int size = S.size();
        int s = 0;
        int e = 0;
        for (int i = 0; i < size; ++i) {
            if (i == size - 1 || S[i] != S[i + 1]) {
                if (e - s > 1) {
                    vector<int> index;
                    index.push_back(s);
                    index.push_back(e);
                    indices.push_back(index);
                }

                s = e = i + 1;
            }
            else {
                ++e;
            }
        }

        return indices;
    }
};