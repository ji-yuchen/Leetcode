/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < n; ++i){
            if(fast->next == NULL){
                return head->next;//At first, I use "return head", return the original List in condition "n > length of List". Then I find that the offical answer cut the head ListNoed in this condition. Well, it's easy now. we return head->next, solving the "[1], 1" input at the same time. 
            }else{
                fast = fast->next;
            }            
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
