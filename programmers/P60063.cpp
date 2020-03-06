#include <string>
#include <vector>
#include <queue>

using namespace std;

struct position{
    int x1, y1;
    int x2, y2;
    int sec;
};

int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool visited[100][100][4];  // 0, 1 가로 / 2, 3 세로

bool check(vector<vector<int> >& board, int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) return false;
    
    if (board[y1][x1] == 1 || board[y2][x2] == 1) return false;

    return true;
}

bool if_visited(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        if ((visited[y1][x1][2] && visited[y2][x2][3]) || (visited[y1][x1][3] && visited[y2][x2][2])) return true;
    }
    else {
        if ((visited[y1][x1][0] && visited[y2][x2][1]) || (visited[y1][x1][1] && visited[y2][x2][0])) return true;
    }

    return false;
}

void check_visited(position& pos) {
    // 세로
    if (pos.x1 == pos.x2) {
        visited[pos.y1][pos.x1][2] = visited[pos.y1][pos.x1][3] = visited[pos.y2][pos.x2][2] = visited[pos.y2][pos.x2][3] = true;
    }
    else {
        visited[pos.y1][pos.x1][0] = visited[pos.y1][pos.x1][1] = visited[pos.y2][pos.x2][0] = visited[pos.y2][pos.x2][1] = true;
    }
}

int solution(vector<vector<int> > board) {
    int answer = 0;

    n = board.size();

    position first = {0, 0, 1, 0, 0};
    queue<position> queue;
    queue.push(first);
    check_visited(first);

    while (!queue.empty()) {
        position front = queue.front();
        queue.pop();

        if ((front.x1 == n - 1 && front.y1 == n - 1) ||
            (front.x2 == n - 1 && front.y2 == n - 1)) return front.sec;

        // 이동
        for (int i = 0; i < 4; i++) {
            int next_x1 = front.x1 + dx[i];
            int next_y1 = front.y1 + dy[i];
            int next_x2 = front.x2 + dx[i];
            int next_y2 = front.y2 + dy[i];

            if (check(board, next_x1, next_y1, next_x2, next_y2) && !if_visited(next_x1, next_y1, next_x2, next_y2)) {
                position next = {next_x1, next_y1, next_x2, next_y2, front.sec + 1};
                queue.push(next);
                check_visited(next);
            }
        }

        // 회전
        int r_x = 0;
        int r_y = 0;
        if (front.x1 == front.x2) r_x = 1;
        else r_y = 1;

        for (int i = -1; i < 2; i += 2) {
            if (check(board, front.x1 + r_x * i, front.y1 + r_y * i, front.x2 + r_x * i, front.y2 + r_y * i)) {
                if (!if_visited(front.x1, front.y1, front.x1 + r_x * i, front.y1 + r_y * i)) {
                    position next = {front.x1, front.y1, front.x1 + r_x * i, front.y1 + r_y * i, front.sec + 1};
                    queue.push(next);
                    check_visited(next);
                }
                if (!if_visited(front.x2, front.y2, front.x2 + r_x * i, front.y2 + r_y * i)) {
                    position next = {front.x2, front.y2, front.x2 + r_x * i, front.y2 + r_y * i, front.sec + 1};
                    queue.push(next);
                    check_visited(next);
                }
            }
        }
    }
    
    return answer;
}