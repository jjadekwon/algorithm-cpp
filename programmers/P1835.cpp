#include <string>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int answer;

bool check(string friends, vector<string> data) {

    for (string s : data) {
        bool result = false;

        char first = s[0];
        char second = s[2];
        char op = s[3];
        int space = s[4] - '0';
        
        int first_index = 0;
        int second_index = 0;
        for (int i = 0; i < friends.length(); i++) {
            if (friends[i] == first) {
                first_index = i;
            }
            else if (friends[i] == second) {
                second_index = i;
            }
        }

        int dist = abs(first_index - second_index) - 1;
        switch (op) {
            case '=':
                if (dist == space) result = true;
            break;
            case '<':
                if (dist < space) result = true;
            break;
            case '>':
                if (dist > space) result = true;
            break;
        }

        if (!result) return false;
    }

    return true;
}

void swap(string& friends, int i, int j) {
    char temp = friends[i];
    friends[i] = friends[j];
    friends[j] = temp;
}

void permutation(string friends, vector<string> data, int k, int n) {
    if (k == n) {
        if (check(friends, data)) answer++;
        return;
    }
    
    for (int i = k; i < n; i++) {
        swap(friends, i, k);
        permutation(friends, data, k + 1, n);
        swap(friends, i, k);
    }
}

int solution(int n, vector<string> data) {
    answer = 0;

    string friends = "ACFJMNRT";
    permutation(friends, data, 0, friends.length());
    
    return answer;
}
