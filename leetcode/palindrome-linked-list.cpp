// Runtime: 36 ms, faster than 10.56% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 15.2 MB, less than 5.17% of C++ online submissions for Palindrome Linked List.

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        vector<int> v;
        ListNode* node = head;
        while (node != nullptr) {
            v.push_back(node->val);
            node = node->next;
        }

        node = head;
        int size = v.size();
        for (int i = size - 1; i >= size / 2; --i) {
            if (node->val != v[i]) return false;
            node = node->next;
        }

        return true;
    }
};