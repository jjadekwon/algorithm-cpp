#include <string>
#include <vector>

using namespace std;

int getDay(int progress, int speed) {
    int p = (100 - progress) / speed;
    int q = (100 - progress) % speed;
    int day = q == 0 ? p : p + 1;
    
    return day;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int count = 1;
    int idx = 0;
    int size = progresses.size();
    while (true) {
        if (idx >= size) break;

        int day = getDay(progresses[idx], speeds[idx]);
        
        for (int j = idx + 1; j < size; j++) {
            int day_next = getDay(progresses[j], speeds[j]);
            if (day_next > day) {
                idx = j - 1;
                break;
            }
            else if (j == size - 1) {
                idx = j;
                count++;
                break;
            }
        
            count++;
        }
        
        answer.push_back(count);
        count = 1;
        idx++;
    }
    
    return answer;
}

int main() {
    vector<int> progresses;
    vector<int> speeds;
    
    progresses.push_back(40);
    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);
    progresses.push_back(60);
    progresses.push_back(65);

    speeds.push_back(60);
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);
    speeds.push_back(10);
    speeds.push_back(7);

    solution(progresses, speeds);

    return 0;
}