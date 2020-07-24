// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Simple recursive search

// O(N), faster than 75%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int biggest = -0x7fffffff;
    
    int helper(TreeNode* root) {
        if (root -> left == NULL && root -> right == NULL) {
            biggest = max(biggest, root -> val);
            return root -> val;
        }
        int left = -0x7fffffff, right = -0x7fffffff;
        if (root -> left != NULL) {
            left = helper(root -> left);
            biggest = max(biggest, left);
        }
        if (root -> right != NULL) {
            right = helper(root -> right);
            biggest = max(biggest, right);
        }
        if (left == -0x7fffffff) {
            biggest = max(biggest, max(root -> val, root -> val + right));
            return max(root -> val, root -> val + right);
        } else if (right == -0x7fffffff) {
            biggest = max(biggest, max(root -> val, root -> val + left));
            return max(root -> val, root -> val + left);
        }
        biggest = max(biggest, max(root -> val, max(root -> val + left, max(root -> val + right, root -> val + left + right))));
        return max(root -> val, max(root -> val, max(root -> val + left, root -> val + right)));
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return biggest;
    }
};
