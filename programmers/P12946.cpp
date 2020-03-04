#include <string>
#include <vector>

using namespace std;

void hanoi(int first, int second, int third, int n, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({first, third});
    }
    else {
        hanoi(first, third, second, n - 1, answer);
        answer.push_back({first, third});
        hanoi(second, first, third, n - 1, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(1, 2, 3, n, answer);
    return answer;
}