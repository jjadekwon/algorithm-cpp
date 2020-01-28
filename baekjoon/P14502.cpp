#include <iostream>

using namespace std;

int N, M;
int maxArea;
int arr[8][8];
int copiedArr[8][8];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void setWalls(int, int);
void spreadVirus(int, int);
int getSafeArea();
void copyArr();

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    setWalls(0, 0);

    cout << maxArea << endl;

    return 0;
}

void setWalls(int idx, int count) {
    if (count == 3) {
        copyArr();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (copiedArr[i][j] == 2) spreadVirus(j, i);
            }
        }

        int area = getSafeArea();
        if (maxArea < area) maxArea = area;
        
        return;
    }

    int max = N * M;
    for (int i = idx; i < max; i++) {
        int y = i / M;
        int x = i % M;
        if (arr[y][x] == 0) {
            arr[y][x] = 1;
            setWalls(i + 1, count + 1);
            arr[y][x] = 0;
        }
    }
}

void spreadVirus(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int moveX = x + dx[i];
        int moveY = y + dy[i];

        if (moveX >= 0 && moveX < M && moveY >= 0 && moveY < N) {
            if (copiedArr[moveY][moveX] == 0) {
                copiedArr[moveY][moveX] = 2;
                spreadVirus(moveX, moveY);
            }
        }
    }
}

int getSafeArea() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (copiedArr[i][j] == 0) count++;
        }
    }

    return count;
}

void copyArr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            copiedArr[i][j] = arr[i][j];
        }
    }
}