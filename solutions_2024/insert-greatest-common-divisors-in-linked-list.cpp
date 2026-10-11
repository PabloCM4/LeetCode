    //  Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* num1 = head;
        ListNode* num2 = head->next;
        while(num2 != nullptr)
        {
            ListNode* num3 = new ListNode(std::gcd(num1->val,num2->val),num2);
            num1->next = num3;
            num1 = num3->next;
            num2 = num1->next;
        }

        return head;   
    }
};