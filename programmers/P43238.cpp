#include <string>
#include <vector>

#define MAX 1000000000000000000

using namespace std;

long long solution(int n, vector<int> times) {
    long long min = 0;
    long long max = MAX;
    long long mid = 0;
    
    while (min <= max) {
        mid = (min + max) / 2;
        
        long long sum = 0;
        for (int time : times) sum += mid / time;
        
        if (sum < n) min = mid + 1;
        else max = mid - 1;
    }
    
    return min;
}

int main() {
    vector<int> times;
    times.push_back(7);
    times.push_back(10);
    solution(6, times);
}