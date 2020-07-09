#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int s = 0;
    for (int i = 0; i < number.size() - k; ++i) {
        char max = 0;
        int maxIdx = 0;
        for (int j = s; j <= i + k; ++j) {
            if (max < number[j]) {
                max = number[j];
                maxIdx = j;
            }
        }
        answer.push_back(max);
        number[maxIdx] = '0';
        s = maxIdx + 1;
    }

    return answer;
}