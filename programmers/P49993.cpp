#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); ++i) {
        int prevIdx = -1;
        bool check = true;
        for (int j = 0; j < skill_trees[i].length(); ++j) {
            size_t st = skill.find(skill_trees[i][j]);
            if (st != skill.npos) {
                if (st - prevIdx == 1) {
                    prevIdx = st;
                }
                else {
                    check = false;
                    break;
                }
            }
        }
        if (check) ++answer;
    }

    return answer;
}