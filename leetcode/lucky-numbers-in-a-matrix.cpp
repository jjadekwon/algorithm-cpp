// Runtime: 36 ms, faster than 9.82% of C++ online submissions for Lucky Numbers in a Matrix.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Lucky Numbers in a Matrix.

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int> > row_min;
        for (int i = 0; i < n; ++i) {
            int min = matrix[i][0];
            int index = 0;
            for (int j = 1; j < m; ++j) {
                if (min > matrix[i][j]) {
                    min = matrix[i][j];
                    index = j;
                }
            }

            row_min.push_back(make_pair(index, min));
        }
        
        map<int, int> max_col;
        for (auto row : row_min) {
            if (max_col.count(row.first) > 0) continue;

            max_col[row.first] = matrix[0][row.first];
            for (int i = 1; i < n; ++i) {
                if (max_col[row.first] < matrix[i][row.first]) max_col[row.first] = matrix[i][row.first];
            }
        }

        vector<int> result;
        for (auto row : row_min) {
            if (max_col[row.first] == row.second) result.push_back(row.second);
        }
        
        return result;
    }
};