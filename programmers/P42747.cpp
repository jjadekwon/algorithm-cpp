#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    int max = 0;
    int size = citations.size();
    for (int i = 0; i < size; ++i) {
        if (i + 1 <= citations[i]) max = i + 1;
    }

    return max;
}