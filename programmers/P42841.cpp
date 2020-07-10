#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > baseball) {
    int answer = 0;
    
    for (int i = 123; i <= 987; ++i) {
        string number = to_string(i);
        if (number[0] == number[1] || number[0] == number[2] || number[1] == number[2]) continue;
        if (number[0] == '0' || number[1] == '0' || number[2] == '0') continue;

        bool check = true;
        for (int j = 0; j < baseball.size(); ++j) {
            string n = to_string(baseball[j][0]);

            int strike = 0;
            int ball = 0;
            for (int a = 0; a < 3; ++a) {
                for (int b = 0; b < 3; ++b) {
                    if (a == b && number[a] == n[b]) ++strike;
                    else if (number[a] == n[b]) ++ball;
                }
            }

            if (strike != baseball[j][1] || ball != baseball[j][2]) {
                check = false;
                break;
            }
        }

        if (check) ++answer;
    }

    return answer;
}