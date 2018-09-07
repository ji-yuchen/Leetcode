/*
https://leetcode.com/submissions/detail/174408061/

Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//Pay attention to judge "head" and "head->next" is NULL when used. 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return head;
        while(head!=NULL&&head->val == val){
            head = head->next;
        }
        ListNode* Orihead = head;
        while(head!=NULL&&head->next!=NULL){
            if(head->next->val==val){
                head->next = head->next->next;
            }
            if(head->next!=NULL&&head->next->val!=val)
            {
                head = head->next;
            }
            
        }
        return Orihead;
        
    }
};
