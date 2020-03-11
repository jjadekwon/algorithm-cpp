#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[1] < b[1];

    return a[0] < b[0];
}

int solution(vector<vector<int> > routes) {
    sort(routes.begin(), routes.end(), comp);

    int end = routes[0][1];
    int count = 1;
    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] > end) {
            count++;
            end = routes[i][1];
        }
        if (routes[i][1] < end) {
            end = routes[i][1];
        }
    }

    return count;
}
