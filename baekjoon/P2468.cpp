#include <iostream>

using namespace std;

int N;
int arr[100][100];
int copied[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int rainfall) {
    copied[y][x] = rainfall;

    for (int i = 0; i < 4; i++) {
        int moveX = x + dx[i];
        int moveY = y + dy[i];

        if (moveX >= 0 && moveX < N && moveY >=0 && moveY < N) {
            if (copied[moveY][moveX] > rainfall) {
                dfs(moveX, moveY, rainfall);
            }
        }
    }
}

void copyArr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            copied[i][j] = arr[i][j];
        }
    }
}

int main() {
    cin >> N;

    int min = 101;
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] < min) min = arr[i][j];
            if (arr[i][j] > max) max = arr[i][j];
        }
    }

    int maxCount = 1;
    int count = 0;
    for (int i = min; i <= max; i++) {
        count = 0;
        copyArr();

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (copied[j][k] > i) {
                    count++;
                    dfs(k, j, i);
                }
            }
        }

        if (maxCount < count) maxCount = count;
    }

    cout << maxCount << endl;

    return 0;
}