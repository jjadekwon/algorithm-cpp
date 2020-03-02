#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    vector<int> number;
    for (int i = 1; i <= n; i++) number.push_back(i);
    
    while (number.size() > 0) {
        long long fac = 1;
        for (int i = 2; i < n; i++) fac *= i;
        
        long long index = (k - 1) / fac;
        answer.push_back(number[index]);
        number.erase(number.begin() + index);

        k %= fac;
        if (k == 0) k = fac;
        n--;
    }
    
    return answer;
}