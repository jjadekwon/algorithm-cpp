#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    vector<int> topIndice;
    int size = board.size();
    for (int col = 0; col < size; ++col) {
        for (int row = 0; row < size; ++row) {
            if (board[row][col] == 0) continue;

            topIndice.push_back(row);
            break;
        }
    }

    stack<int> s;
    int answer = 0;
    for (int i = 0; i < moves.size(); ++i) {
        int col = moves[i] - 1;
        int row = topIndice[col];

        if (row == size) continue;
        
        if (s.empty() || s.top() != board[row][col]) {
            s.push(board[row][col]);
        }
        else {
            s.pop();
            answer += 2;
        }

        ++topIndice[col];
    }

    return answer;
}