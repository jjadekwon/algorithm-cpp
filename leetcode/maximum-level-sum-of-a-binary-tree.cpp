// Runtime: 256 ms, faster than 11.96% of C++ online submissions for Maximum Level Sum of a Binary Tree.
// Memory Usage: 69.4 MB, less than 100.00% of C++ online submissions for Maximum Level Sum of a Binary Tree.

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> queue;

        queue.push(root);

        int maxSum = 0;
        int maxLevel = 0;
        int level = 1;
        while (!queue.empty()) {
            int sum = 0;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                sum += node->val;

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);

                queue.pop();
            }

            if (maxSum < sum) {
                maxSum = sum;
                maxLevel = level;
            }

            level++;
        }
        
        return maxLevel;
    }
};