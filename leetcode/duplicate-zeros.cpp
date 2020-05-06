#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> result;

        int size = arr.size();
        for (int i = 0; i < size; ++i) {
            if (result.size() == size) break;

            result.push_back(arr[i]);
            if (arr[i] == 0 && result.size() < size) {
                result.push_back(0);
            }
        }
        
        arr = result;
    }
};

int main() {
    Solution s;
    vector<int> test;
    // test.push_back(1);
    // test.push_back(0);
    // test.push_back(2);
    // test.push_back(3);
    // test.push_back(0);
    // test.push_back(4);
    // test.push_back(5);
    // test.push_back(0);
    test.push_back(0);
    test.push_back(0);
    test.push_back(0);
    test.push_back(0);
    test.push_back(0);
    test.push_back(0);
    test.push_back(0);
    s.duplicateZeros(test);
    return 0;
}