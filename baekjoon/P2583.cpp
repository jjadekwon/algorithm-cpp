#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int size = 0;

void dfs(int y, int x) {
    arr[y][x] = 1;
    size++;

    for (int i = 0; i < 4; i++) {
        int moveX = x + dx[i];
        int moveY = y + dy[i];

        if (moveY >= 0 && moveY < N && moveX >= 0 && moveX < M) {
            if (arr[moveY][moveX] == 0) {
                dfs(moveY, moveX);
            }
        }
    }
}

int main() {
    int K;
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                arr[y][x] = 1;
            }
        }
    }

    vector<int> sizes;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                size = 0;

                dfs(i, j);

                count++;
                sizes.push_back(size);
            }
        }
    }

    sort(sizes.begin(), sizes.end());

    cout << count << endl;
    for (int i = 0; i < sizes.size(); i++) {
        cout << sizes[i] << " ";
    }
    
    return 0;
}