    //  Link: https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        ListNode* checker = head;
        ListNode* nexter = head;
        vector<ListNode*> answer(k,nullptr);    //  answer filled with nullptr in case there are more groups than nodes
        int n_nodes = 0, elem_each, elem_extra, counter = 0;

        while(checker)  //  We count the number of total elements
        {
            n_nodes++;
            checker = checker->next;
        }
        checker = head; //  Move back checker to the head after counting

        elem_each = n_nodes / k;    //  There will be n_nodes/k as default in each group
        elem_extra = n_nodes % k;   //  We will increase this number of groups by 1 more elem
        while(head)
        {
            for(int i=0; i < elem_each; i++)    //  Nexter advance the default nodes for group
            {
                nexter = nexter->next;
            }
            if(elem_extra)  //  Nexter advance one more in case we need it
            {
                nexter = nexter->next;
                elem_extra--;
            }

            while(checker->next != nexter) checker = checker->next; //  Checker advance before nexter to end the group

            checker->next = nullptr;    //  Checker set to null the next node to end it.
            answer[counter] = head; //  The head is set in the answer with the correct number of nodes
            head = nexter;  //  Go to the more advanced position to continue with the loop
            checker = nexter;
            counter++;  //  Add 1 to counter to set the next group in the correct position of the answer
        }
        

        return answer;
    }
};