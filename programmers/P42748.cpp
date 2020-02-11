#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;

    for (vector<int> command : commands) {
        vector<int> sorted;
        sorted.assign(array.begin() + (command[0] - 1), array.begin() + command[1]);
        
        sort(sorted.begin(), sorted.end());
        answer.push_back(sorted[command[2] - 1]);
    }
    
    return answer;
}