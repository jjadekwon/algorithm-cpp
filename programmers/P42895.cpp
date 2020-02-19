#include <string>
#include <iostream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define MAX 8
map<int, set<int> > dp;

bool check_number(int index, int number, int result) {
    if (result == number) return true;
    if (result == 0) return false;

    dp[index].insert(result);
    return false;
}

int solution(int N, int number) {
    int answer = -1;

    if (N == number) return 1;

    dp[1].insert(N);

    bool check = false;
    for (int i = 2; i <= MAX; i++) {
        // i가 5인 경우
        // N이 4개일 때 결과(j) & N이 1개일 때 결과(k) 연산
        // N이 3개일 때 결과(j) & N이 2개일 때 결과(k) 연산
        for (int j = (i + 1) / 2; j < i; j++) {
            for (auto j_it = dp[j].begin(); j_it != dp[j].end(); j_it++) {

                int k = i - j;
                for (auto k_it = dp[k].begin(); k_it != dp[k].end(); k_it++) {
                    if (check_number(i, number, *j_it * *k_it)) {
                        check = true;
                        break;
                    }
                    if (check_number(i, number, *j_it / *k_it)) {
                        check = true;
                        break;
                    }
                    if (check_number(i, number, *j_it + *k_it)) {
                        check = true;
                        break;
                    }
                    if (check_number(i, number, *j_it - *k_it)) {
                        check = true;
                        break;
                    }
                    if (check_number(i, number, *k_it - *j_it)) {
                        check = true;
                        break;
                    }
                }
            }
            if (check) break;
        }

        if (check) return i;

        int num = N;
        for (int j = 1; j < i; j++) {
            num += N * pow(10, j);
        }
        if (num == number) {
            return i;
        }
        else {
            dp[i].insert(num);
        }
    }

    return answer;
}

int main() {
    cout << solution(5, 23) << endl;
    return 0;
}