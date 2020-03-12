#include <vector>
#include <queue>

using namespace std;

int MOD = 20170805;

int right[501][501];
int down[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (i == 1 && j == 1) {
                right[i][j] = down[i][j] = 1;
                continue;
            }

            switch (city_map[i - 1][j - 1]) {
                case 0:
                    right[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
                    down[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
                    break;
                case 1:
                    right[i][j] = down[i][j] = 0;
                    break;
                case 2:
                    right[i][j] = right[i][j - 1];
                    down[i][j] = down[i - 1][j];
                    break;
            }
        }
    }

    return right[m][n];
}