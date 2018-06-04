/*
https://leetcode.com/problems/reverse-linked-list/description/
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        ListNode* pre = new_head;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* pnext = curr->next;
            if(pnext == NULL)
                new_head = curr; 
            curr->next = pre;
            pre = curr;
            curr = pnext;
        }
        return new_head;
    }
};
