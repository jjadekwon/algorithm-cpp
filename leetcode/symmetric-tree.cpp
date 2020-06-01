// Runtime: 4 ms, faster than 82.35% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16.5 MB, less than 8.48% of C++ online submissions for Symmetric Tree.

#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        if (root->left == nullptr && root->right == nullptr) return true;
        
        if (root->left == nullptr || root->right == nullptr) return false;

        deque<TreeNode*> dq;
        dq.push_back(root->left);
        dq.push_back(root->right);

        while (dq.size() > 0) {
            int size = dq.size();
            for (int i = 0; i < size / 2; ++i) {
                if (dq[i] == nullptr && dq[size - i - 1] == nullptr) continue;
                if (dq[i] == nullptr || dq[size - i - 1] == nullptr) return false;
                if (dq[i]->val != dq[size - i - 1]->val) return false;
            }
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = dq.front();
                dq.pop_front();

                if (node == nullptr) continue;

                dq.push_back(node->left);
                dq.push_back(node->right);
            }
        }

        return true;
    }
};