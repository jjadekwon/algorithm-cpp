// Runtime: 1232 ms, faster than 5.01% of C++ online submissions for Time Needed to Inform All Employees.
// Memory Usage: 86.9 MB, less than 100.00% of C++ online submissions for Time Needed to Inform All Employees.

#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int> > map;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] == -1) continue;

            if (map.count(manager[i]) == 0) {
                vector<int> subordinates;
                subordinates.push_back(i);
                map.insert(make_pair(manager[i], subordinates));
            }
            else {
                map.at(manager[i]).push_back(i);
            }
        }

        queue<pair<int, int> > queue;
        queue.push(make_pair(headID, 0));
        int time = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                auto front = queue.front();
                queue.pop();

                if (time < front.second) {
                    time = front.second;
                }

                if (map.count(front.first) == 0) continue;

                for (int subordinate : map.at(front.first))
                    queue.push(make_pair(subordinate, front.second + informTime[front.first]));
            }
        }

        return time;
    }
};