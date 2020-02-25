#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 20000

int arr[MAX][MAX];
bool visited[MAX];
int dist[MAX];

int solution(int n, vector<vector<int> > edge) {
    int answer = 0;
    for (vector<int> v : edge) {
        arr[v[0] - 1][v[1] - 1] = arr[v[1] - 1][v[0] - 1] = 1;
    }

    queue<int> queue;
    queue.push(0);
    visited[0] = true;
    
    int distance = 0;
    while (!queue.empty()) {
        int size = queue.size();
        distance++;

        for (int i = 0; i < size; i++) {
            int pop = queue.front();
            queue.pop();

            for (int j = 0; j < n; j++) {
                if (!visited[j] && arr[pop][j]) {
                    queue.push(j);
                    visited[j] = true;
                    dist[j] = distance;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == distance - 1) answer++;
    }

    return answer;
}