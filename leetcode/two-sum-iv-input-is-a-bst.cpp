// Runtime: 52 ms, faster than 65.26% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 35.7 MB, less than 5.00% of C++ online submissions for Two Sum IV - Input is a BST.

#include <vector>

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> list;
        inorder(root, list);

        int l = 0;
        int r = list.size() - 1;
        bool result = false;
        while (l < r) {
            int sum = list[l] + list[r];
            if (sum == k) {
                result = true;
                break;
            }
            
            if (sum < k) ++l;
            else --r;
        }

        return result;
    }

    void inorder(TreeNode *root, vector<int>& list) {
        if (root == nullptr) return;

        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
};