#include <string>
#include <vector>

using namespace std;

int answer = 0;
void dfs(vector<int> numbers, int k, int sum, int target) {
    if (k == numbers.size()) {
        if (sum == target) answer++;
        return;
    }

    dfs(numbers, k + 1, sum + numbers[k], target);
    dfs(numbers, k + 1, sum - numbers[k], target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    
    return answer;
}