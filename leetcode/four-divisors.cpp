// Runtime: 56 ms, faster than 61.76% of C++ online submissions for Four Divisors.
// Memory Usage: 12.7 MB, less than 36.64% of C++ online submissions for Four Divisors.

#include <vector>

using namespace std;

class Solution {
public:
    bool arr[100001];
    int sumFourDivisors(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += sumOfDivisors(nums[i]);
        }

        return sum;
    }

    int sumOfDivisors(int& num) {
        int count = 2;
        int sum = 1 + num;
        for (int i = 2; i * i <= num; ++i) {
            int p = num / i;
            int q = num % i;
            if (q == 0) {
                ++count;
                sum += i;
                if (p != i) {
                    ++count;
                    sum += p;
                }
            }
            if (count > 4) break;
        }

        return count == 4 ? sum : 0;
    }
};