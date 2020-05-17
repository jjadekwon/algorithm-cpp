// Runtime: 4 ms, faster than 47.35% of C++ online submissions for Largest Time for Given Digits.
// Memory Usage: 9.5 MB, less than 10.00% of C++ online submissions for Largest Time for Given Digits.

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());

        string max = "";
        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];
            if (hour < 24 && minute < 60) {
                string time = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
                if (max < time) max = time;
            }
        } while (next_permutation(A.begin(), A.end()));

        return max;
    }
};