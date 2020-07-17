#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int count = 0;
    int l = 0;
    int r = people.size() - 1;
    while (l <= r) {
        if (people[l] + people[r] > limit) {
            --r;
        }
        else {
            ++l;
            --r;
        }
        ++count;
    }

    return count;
}