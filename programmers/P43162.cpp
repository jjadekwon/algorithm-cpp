#include <string>
#include <vector>

using namespace std;

bool visited[200];
void dfs(int idx, int n, vector<vector<int>> computers) {
    visited[idx] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && computers[idx][i]) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}