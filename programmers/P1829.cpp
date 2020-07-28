#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int val, int x, int y, int m, int n, int &count, vector<vector<bool> >& visited, vector<vector<int> >& picture) {
    ++count;
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && !visited[nextX][nextY] && val == picture[nextX][nextY]) {
            dfs(val, nextX, nextY, m, n, count, visited, picture);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    vector<vector<bool> > visited;
    for (int i = 0; i < m; ++i) {
        vector<bool> v;
        for (int j = 0; j < n; ++j) {
            v.push_back(false);
        }
        visited.push_back(v);
    }

    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < picture.size(); ++i) {
        for (int j = 0; j < picture[0].size(); ++j) {
            if (picture[i][j] != 0 && !visited[i][j]) {
                int count = 0;
                ++number_of_area;
                dfs(picture[i][j], i, j, m, n, count, visited, picture);
                if (max_size_of_one_area < count) max_size_of_one_area = count;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}