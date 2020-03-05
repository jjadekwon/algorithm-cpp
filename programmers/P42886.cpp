#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    sort(weight.begin(), weight.end());

    // 제일 작은 추
    int sum = weight[0];
    for (int i = 1; i < weight.size(); i++) {
        if (weight[i] > sum + 1) break;

        sum += weight[i];
    }

    return sum + 1;
}