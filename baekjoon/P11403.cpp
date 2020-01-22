#include <iostream>

#define MAX 100

using namespace std;

int map[MAX][MAX];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 0 && map[i][k] && map[k][j]) map[i][j] = 1;
                if (map[j][i] == 0 && map[j][k] && map[k][i]) map[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}