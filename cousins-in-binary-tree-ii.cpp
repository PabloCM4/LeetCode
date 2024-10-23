    //  Link: https://leetcode.com/problems/cousins-in-binary-tree-ii
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> sum;
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() )
        {
            int lvl_size = q.size();
            long long lvl_sum = 0;
            for(int i = 0; i < lvl_size; i++)
            {
                TreeNode* aux = q.front();

                q.pop();

                lvl_sum += aux->val;

                if(aux->left) q.push(aux->left);
                if(aux->right) q.push(aux->right);
            }
            sum.push_back(lvl_sum);
        }

        root->val = 0;
        q.push(root);
        int lvl = 0;
        while( !q.empty() )
        {
            int lvl_size = q.size();
            for(int i = 0; i < lvl_size; i++)
            {
                if(lvl < 1)
                {
                    TreeNode* aux = q.front();
                    q.pop();
                    if(aux->left)
                    {
                        q.push(aux->left); 
                        aux->left->val = 0; 
                    } 
                    if(aux->right)
                    {
                        q.push(aux->right);
                        aux->right->val = 0;
                    } 
                }
                else
                {
                    TreeNode* aux = q.front();
                    q.pop();
                    int brothers = 0;
                    if(aux->left) brothers += aux->left->val;
                    if(aux->right) 
                    {
                        brothers += aux->right->val;
                        q.push(aux->right);
                        aux->right->val = sum[lvl+1] - brothers;
                    }
                    if(aux->left)
                    {
                        q.push(aux->left); 
                        aux->left->val = sum[lvl+1] - brothers;
                    } 
                }
                
            }

            lvl++;
        }

        return root;
    }
};