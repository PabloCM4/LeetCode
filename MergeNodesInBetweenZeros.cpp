//Link https://leetcode.com/problems/merge-nodes-in-between-zeros/  

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
 
 //Could be optimized: instead of creating new ListNode, use the one given as the result.
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;  //  Skip first 0
        ListNode* result = new ListNode();  //  Create result ListNode which includes the solution

        ListNode* adder = result;   // Another pointer to add the numbers in the result (so we don´t lose the head of the result)

        while( head->next != nullptr )  //  While we are not in the last 0
        {
            if(head->val == 0)  
            {
                adder->next = new ListNode();   //  Create another node for the following numbers
                adder = adder->next;
            }
            else
            {
                adder->val += head->val;
            }

            head = head->next;
        }

        return result;
    }
};