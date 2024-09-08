    //  Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        ListNode* checker = head;
        ListNode* prev = head;

        set<int> myList;

        for(int x : nums)
        {
            myList.insert(x);
        }

        while(checker)
        {

            if( myList.find(checker->val) != myList.end() )
            {
                if(checker == head) head=head->next;
                else prev->next = checker->next;
            }

            checker = checker->next;
            if( (prev->next != checker) || (prev->next == head) ) prev = prev->next;
            
        }
        return head;
    }
};