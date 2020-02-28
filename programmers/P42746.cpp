#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> s_numbers;
    for (int n : numbers) s_numbers.push_back(to_string(n));

    sort(s_numbers.begin(), s_numbers.end(), comp);

    for (string s : s_numbers) answer += s;
    
    if (answer[0] == '0') return "0";

    return answer;
}
