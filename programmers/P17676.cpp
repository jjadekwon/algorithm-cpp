#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char delimeter) {
    vector<string> v;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimeter)) {
        v.push_back(temp);
    }

    return v;
}

vector<vector<double> > toSeconds(vector<string>& lines) {
    vector<vector<double> > seconds;
    for (int i = 0; i < lines.size(); ++i) {
        vector<string> result = split(lines[i], ' ');
        string times = result[1];
        double sec = stod(result[2].substr(0, result[2].size() - 1));

        vector<string> s = split(times, ':');
        
        double end = stod(s[0]) * 3600 + stod(s[1]) * 60 + stod(s[2].substr(0, 2)) + stod(s[2].substr(3, 3)) * 0.001;
        double start = end - sec + 0.001;

        vector<double> temp;
        temp.push_back(start);
        temp.push_back(end);

        seconds.push_back(temp);
    }

    return seconds;
}

int solution(vector<string> lines) {
    vector<vector<double> > seconds = toSeconds(lines);

    int max = 1;
    for (int i = 0; i < seconds.size(); ++i) {
        int count = 1;
        double start = seconds[i][1];
        double end = start + 1;

        for (int j = 0; j < seconds.size(); ++j) {
            if (i == j) continue;
            if (start <= seconds[j][1] && end > seconds[j][0]) ++count;
        }

        if (max < count) max = count;
    }

    return max;
}