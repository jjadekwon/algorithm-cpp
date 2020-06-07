// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Broken Calculator.
// Memory Usage: 6.1 MB, less than 33.07% of C++ online submissions for Broken Calculator.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X > Y) return X - Y;

        int count = 0;
        while (true) {
            if (Y <= X) return count + (X - Y);

            if (Y % 2 == 0) Y /= 2;
            else ++Y;
            
            ++count;
        }

        return count;
    }
};