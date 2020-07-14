#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int height = 1; height <= sqrt(yellow); ++height) {
        if (yellow % height == 0) {
            int width = yellow / height;
            int b = (width * 2) + (height * 2) + 4;
            if (brown == b) {
                answer.push_back(width + 2);
                answer.push_back(height + 2);
                break;
            }
        }
    }

    return answer;
}