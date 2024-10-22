    //  Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

//  Very inneficient way of getting the sum before sorting, below answer from leetcode explained
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
    vector<long long> answer;

    // Creates a function that goes through every position of the tree. Add the value of the position in a cell of the vector corresponding to the level
    void SumTree (TreeNode* head, int level)
    {
        // If there is no cell for the level, create it with the value of the position
        if ( answer.size() <= level ) answer.push_back(head->val);
        // Else, add the value of the position to the corresponding cell
        else answer[level] += head->val;

        // Continue the sum to the left
        if(head->left) SumTree(head->left, level+1);
        // Continue the sum to the right
        if(head->right) SumTree(head->right, level+1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {

        if(root)
        {   
            // Call the function to sum every position and get the answer
            SumTree( root, 0 );
            
            // Check if we should return -1
            if(answer.size() < k) return -1;
            else
            {
                // Sort the answer from bigger to lower
                sort(answer.begin(), answer.end(), greater<long long>() );
                // Return the k largest value
                return answer[k-1];
            }
        }
        else return -1;
        
    }
};

//  ******************************************  //
//  Answer copied from LeetCode, explanation by me

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans;   //  Same as me, a vector to store the sums of each level
        queue<TreeNode*>q;  //  Creates a queue, it will save the next level positions to sum
        q.push(root);   //  Put in the queue the root
        while(!q.empty()){ 
            //  Get the size of the queue (how many positions on this level, to know how many times iterate)
            int s=q.size(); 

            //  Restart the sum for this level to 0
            long long sum=0;    

            //  Iterate through every position in the same level (if something added later to the queue wont be taken into account for this loop)
            for(int i=0; i<s; i++){ 
                TreeNode*temp=q.front();    //  Get the position and save it
                q.pop();    //  Remove the position from the queue
                sum+=temp->val; //  Sum the value

                //  Add to the queue the next level position (it won´t be taken into account in this level)
                if(temp->left){ 
                    q.push(temp->left); 
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(sum); //  Add the sum to the vector
        }
        if(ans.size()<k){
            return -1;
        }
        //  Sort the vector and return
        sort(ans.begin(), ans.end(), greater<long long>()); 
        return ans[k-1];
    }
};