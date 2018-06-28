/*
https://leetcode.com/problems/sort-list/description/
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
//Each time divided the given list into two sub list. Merge sub list after bottom case return.
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
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1==NULL){
            return h2;
        }
        if(h2==NULL){
            return h1;
        }
        if(h1->val < h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        }else{
            h2->next = merge(h1, h2->next);
            return h2;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* pre = head;
        while(p2!=NULL && p2->next!=NULL){
            pre = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        pre->next = NULL;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(p1);
        return merge(h1, h2);
        
    }
};
