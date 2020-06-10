// Runtime: 8 ms, faster than 34.28% of C++ online submissions for Add Binary.
// Memory Usage: 6.5 MB, less than 60.09% of C++ online submissions for Add Binary.

#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int al = a.length() - 1;
        int bl = b.length() - 1;
        
        int carry = 0;
        while (true) {
            if (carry == 0 && al < 0 && bl < 0) break;

            int sum = carry;
            if (al >= 0) sum += a[al] - '0';
            if (bl >= 0) sum += b[bl] - '0';
            
            if (sum == 2) {
                carry = 1;
                sum = 0;
            }
            else if (sum == 3) {
                carry = 1;
                sum = 1;
            }
            else {
                carry = 0;
            }

            result.push_back(sum + '0');

            --al; --bl;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};