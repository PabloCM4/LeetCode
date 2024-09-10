    //  Link: https://leetcode.com/problems/spiral-matrix-iv/
    
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> answer(m, vector<int>(n, -1));  //  Initialize the matrix with -1

        int m_min = 0, m_max = m, m_act = 0;    //  Variables to handle the column transition
        int n_min = 0, n_max = n, n_act = 0;    //  Variables to handle the row transition

        while(head)
        {
            for(n_act; (n_act < n_max) && head; n_act++)    //  Transition to the right
            {
                answer[m_act][n_act] = head->val;
                head = head->next;
            }
            m_min++;    //  That row is complete so the minimun value we can reach now increases
            m_act++;    //  Move to the next row as this one is already filled
            n_act--;    //  Come back from the last n_act++ which positioned 1 element off.

            for(m_act; (m_act < m_max) && head; m_act++)    //  Transition to the bottom
            {
                answer[m_act][n_act] = head->val;
                head = head->next;
            }
            n_max--;    //  That column is complete so the maximum value we can reach now decreases
            n_act--;    //  Move to the previous column as this one is already filled
            m_act--;    //  Come back from the last m_act++ which positioned 1 element off.

            for(n_act; (n_act >= n_min) && head; n_act--)   //  Transition to the left
            {
                answer[m_act][n_act] = head->val;
                head = head->next;
            }
            m_max--;    //  That row is complete so the maximum value we can reach now decreases
            m_act--;    //  Move to the previous row as this one is already filled
            n_act++;    //  Come back from the last n_act-- which positioned 1 element off.

            for(m_act; (m_act >= m_min) && head; m_act--)   //  Transition to the top
            {
                answer[m_act][n_act] = head->val;
                head = head->next;
            }
            n_min++;    //  That column is complete so the minimum value we can reach now increases
            n_act++;    //  Move to the next column as this one is already filled
            m_act++;    //  Come back from the last m_act-- which positioned 1 element off.
        }
        
        return answer;
    }
};