/*
https://leetcode.com/problems/partition-list/description/

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //I HAVE TRIED modified on the original list: IF cur->val >= x, link cur to an temp list. IF cur->val < x, just move to next list.
 //At last, link extra list to the original modified list.
 //=.= the judgement may be somewhat hard to write clearly...
 //It's not easy for users.
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode dummy1(0);
        ListNode dummy2(0);
        dummy1.next = NULL;
        dummy2.next = NULL;
        ListNode *tail1 = &dummy1;
        ListNode *tail2 = &dummy2;
    
        while (head) {
            ListNode *next = head->next;
            head->next = NULL;
            if (head->val < x) {
                tail1->next = head;
                tail1 = tail1->next;
            } else {
                tail2->next = head;
                tail2 = tail2->next;
            }
            head = next;
        }
        tail1->next = dummy2.next;
        return dummy1.next;
    }
};
