#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<int> timetable_min;
    for (string time : timetable) {
         timetable_min.push_back(60 * stoi(time.substr(0, 2)) + stoi(time.substr(3, 2)));
    }

    sort(timetable_min.begin(), timetable_min.end());

    int size = timetable.size();
    int start = 540;    // 09:00
    int idx = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int bus = start + i * t;
        count = 0;

        while (idx < size) {
            if (timetable_min[idx] <= bus) {
                count++;
                idx++;
            }
            else break;

            if (count % m == 0) break;
        }
    }

    int time = 0;
    // 남은 자리 있음
    if (count < m && idx - 1 < size) {
        time = start + (n - 1) * t;
    }
    else {
        time = timetable_min[idx - 1] - 1;
    }

    int p = time / 60;
    int q = time % 60;
    answer = p < 10 ? "0" + to_string(p) : to_string(p);
    answer += ":";
    answer += q < 10 ? "0" + to_string(q) : to_string(q);

    return answer;
}