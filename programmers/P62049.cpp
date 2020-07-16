#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);

    int size = 1;
    for (int i = 1; i < n; ++i) {
        answer.push_back(0);
        for (int j = size - 1; j >= 0; --j) {
            answer.push_back(!answer[j]);
        }

        size *= 2;
        ++size;
    }

    return answer;
}