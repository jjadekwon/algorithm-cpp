#include <iostream>

#define MAX 1001

using namespace std;

int N;
int arr[MAX][MAX];
bool visited[MAX];

void dfs(int v) {
    visited[v] = true;
    for (int i = 1; i <= N; i++) {
        if (arr[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        arr[u][v] = arr[v][u] = 1;
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}