#include <vector>

using namespace std;

int solution(vector<vector<int> > land)
{
    int row = land.size();
    int col = land[0].size();
    for (int i = 1; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int max = 0;
            for (int k = 0; k < col; ++k) {
                if (j == k) continue;
                if (max < land[i - 1][k]) max = land[i - 1][k];
            }

            land[i][j] += max;
        }
    }

    int answer = 0;
    for (int i = 0; i < col; ++i) {
        if (answer < land[row - 1][i]) answer = land[row - 1][i];
    }
    
    return answer;
}