#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int grades[3] = {};
    int student1[5] = {1, 2, 3, 4, 5};
    int student2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int student3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++) {
        if (student1[i % 5] == answers[i]) grades[0]++;
        if (student2[i % 8] == answers[i]) grades[1]++;
        if (student3[i % 10] == answers[i]) grades[2]++;
    }
    
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (max < grades[i]) max = grades[i];
    }
    
    for (int i = 0; i < 3; i++) {
        if (grades[i] == max) answer.push_back(i + 1);
    }
    
    return answer;
}