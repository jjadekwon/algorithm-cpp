#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Runtime: 52 ms, faster than 33.10% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.

class Solution {
public:
    int f(string& s) {
        int count = 0;
        char smallest = 'z';
        for (char c : s) {
            if (c == smallest) {
                count++;
            }
            else if (c < smallest) {
                count = 1;
                smallest = c;
            }
        }
        
        return count;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answer;

        vector<int> f_queries;
        for (string query : queries) f_queries.push_back(f(query));

        vector<int> f_words;
        for (string word : words) f_words.push_back(f(word));

        sort(f_words.begin(), f_words.end(), greater<int>());

        for (int query : f_queries) {
            int count = 0;
            for (int word : f_words) {
                if (query >= word) break;
                count++;
            }
            answer.push_back(count);
        }

        return answer;
    }
};