#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;

    for (string p : participant) {
        ++m[p];
    }
    
    for (string c : completion) {
        --m[c];
    }

    for (pair<string, int> pair : m) {
        if (pair.second > 0) {
            answer = pair.first;
            break;
        }
    }
    return answer;
}