#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    if (number == 0) return false;
    if (number == 1) return false;
    if (number == 2) return true;
    
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return false;
    }
    
    return true;
}

bool comp(char a, char b) {
    if (a > b) return true;
    return false;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), comp);

    vector<bool> check(stoi(numbers) + 1);
    sort(numbers.begin(), numbers.end());

    do {
        int number = 0;
        for (int i = 1; i <= numbers.length(); i++) {
            number = stoi(numbers.substr(0, i));
            if (!check[number]) {
                if (isPrime(number)) {
                    check[number] = true;
                    answer++;
                }
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return answer;
}