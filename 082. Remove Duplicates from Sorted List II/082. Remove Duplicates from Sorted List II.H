/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode prehead(-1);
        if(head&&head->val==-1)
            prehead.val = 0;
        prehead.next = head;
        ListNode* tmp = &prehead;
        ListNode* cur = tmp;
        int flag = 0;
        while(cur){                 
            while(cur->next && cur->val == cur->next->val){
                cur->next = cur->next->next;
                flag = 1;
            }
            if(flag)
                tmp->next=cur->next; 
            else
                tmp = cur;
            cur = cur->next;
            flag = 0;
        }
        return prehead.next;
        
    }
};



//THIS SOLUTION AVOID SOME JUDGEMENTS IN MY SOLUTION...\

class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head){
    	if(head == NULL || head->next == NULL) return head;
    	ListNode dummy(0);
    	dummy.next = head;
    	head = &dummy;

    	while(head->next && head->next->next){
    		if(head->next->val == head->next->next->val){
    			int val = head->next->val;
    			while(head->next && head->next->val == val){
    				head->next = head->next->next;
    			}
    		}else{
    			head = head->next;
    		}
    	}
    	return dummy.next;
    }
};
