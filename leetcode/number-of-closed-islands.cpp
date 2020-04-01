// Runtime: 8 ms, faster than 97.98% of C++ online submissions for Number of Closed Islands.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Number of Closed Islands.

#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int> >& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return false;
        
        if (grid[i][j] == 1) return true;

        grid[i][j] = 1;

        return dfs(grid, i, j-1) &
               dfs(grid, i, j+1) &
               dfs(grid, i-1, j) &
               dfs(grid, i+1, j);
    }

    int closedIsland(vector<vector<int> >& grid) {
        int count = 0;
        int height = grid.size();
        int width = grid[0].size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};