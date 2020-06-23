// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
// Memory Usage: 5.9 MB, less than 88.46% of C++ online submissions for Reverse Integer.

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while (x != 0) {
            result = result * 10 + x % 10;
            x /= 10;
            
            if (result > INT_MAX || result < INT_MIN) return 0;
        }

        return (int)result;
    }
};