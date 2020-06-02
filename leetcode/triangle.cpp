// Runtime: 8 ms, faster than 71.95% of C++ online submissions for Triangle.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Triangle.

#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if (row == 1) return triangle[0][0];

        int result = INT_MAX;
        for (int i = 1; i < row; ++i) {
            int col = triangle[i].size();
            for (int j = 0; j < col; ++j) {
                if (j == 0) triangle[i][j] += triangle[i-1][j];
                else if (j == col - 1) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                
                if (i == row - 1) result = min(result, triangle[i][j]);
            }
        }

        return result;
    }
};