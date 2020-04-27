// Runtime: 12 ms, faster than 33.09% of C++ online submissions for Maximize Sum Of Array After K Negations.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Maximize Sum Of Array After K Negations.

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int> > queue;

        int sum = 0;
        int minusCnt = 0;
        for (int a : A) {
            sum += a;
            if (a < 0) ++minusCnt;
            queue.push(a);
        }

        while (minusCnt > 0 && K > 0) {
            int top = -queue.top();
            queue.pop();
            queue.push(top);

            sum += (2 * top);
            --K; --minusCnt;
        }

        if (K % 2 != 0) {
            sum += -(2 * queue.top());
        }

        return sum;
    }
};