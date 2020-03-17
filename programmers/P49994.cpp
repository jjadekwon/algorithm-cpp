#include <string>

#define MAX 11

using namespace std;

bool visited[MAX][MAX][MAX][MAX];
int solution(string dirs) {
	int answer = 0;
    int x = 5;
    int y = 5;
    
    int nx = x;
    int ny = y;
    for (char dir : dirs) {
        switch (dir) {
            case 'U': ny = y - 1;
                break;
            case 'D': ny = y + 1;
                break;
            case 'L': nx = x - 1;
                break;
            case 'R': nx = x + 1;
                break;
        }

        if (ny < 0 || ny > MAX - 1 || nx < 0 || nx > MAX - 1) {
            nx = x; ny = y;
            continue;
        }

        if (!visited[y][x][ny][nx] && !visited[ny][nx][y][x]) {
            visited[y][x][ny][nx] = visited[ny][nx][y][x] = true;
            answer++;
        }

        x = nx;
        y = ny;
    }
    
	return answer;
}