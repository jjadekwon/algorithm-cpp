// Runtime: 12 ms, faster than 57.44% of C++ online submissions for Integer to Roman.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Integer to Roman.

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";

        string symbols[7] = {"I", "V", "X", "L", "C", "D", "M"};
        int i = 0;
        int i5 = 1;
        while (num > 0) {
            string roman = "";

            int n = num % 10;
            if (n == 4) {
                roman = symbols[i] + symbols[i5];
            }
            else if (n == 9) {
                roman = symbols[i] + symbols[i + 2];
            }
            else if (n == 5) {
                roman = symbols[i5];
            }
            else {
                if (n > 5 && n < 9) {
                    roman = symbols[i5];
                }

                for (int j = 0; j < n % 5; ++j) {
                    roman += symbols[i];
                }
            }

            result = roman + result;
            i += 2;
            i5 += 2;
            num /= 10;
        }

        return result;
    }
};