// Runtime: 4 ms, faster than 98.89% of C++ online submissions for Baseball Game.
// Memory Usage: 8.4 MB, less than 46.94% of C++ online submissions for Baseball Game.

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;

        int size = ops.size();
        for (int i = 0; i < size; ++i) {
            if (ops[i] == "C") {
                v.pop_back();
            }
            else if (ops[i] == "D") {
                int data = v.back();
                v.push_back(data * 2);
            }
            else if (ops[i] == "+") {
                int data1 = v.back();
                v.pop_back();
                int data2 = v.back();
                v.push_back(data1);
                v.push_back(data1 + data2);
            }
            else {
                v.push_back(stoi(ops[i]));
            }
        }
        
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) sum += v[i];

        return sum;
    }
};