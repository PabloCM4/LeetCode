    //  Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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

    int adder = 0;
    

    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr)    //  If at the end of a branch
        {
            return; //  Go up
        }
    
        inOrderTraversal(root->right);  // Go to the right
        adder += root->val;
        root->val = adder; 
        inOrderTraversal(root->left);   // Go to the left
    }

    TreeNode* bstToGst(TreeNode* root) {
        adder = 0;
        inOrderTraversal(root);
        return root;
    }
};