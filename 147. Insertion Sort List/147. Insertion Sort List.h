/*
https://leetcode.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list

Algorithm of Insertion Sort:
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.
*/

//Build a new listhead to link the sorted listnodes.
//Time complexity: O(N^2); Space complexity: O(1)

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newhead = new ListNode(0);        
        while(head != NULL){
            ListNode* chead = head;
            ListNode* tmphead = newhead;
            head = head->next;
            while(tmphead->next!=NULL){
                if(chead->val <= tmphead->next->val){
                    chead->next = tmphead->next;
                    tmphead->next = chead;                    
                    break;
                }
                tmphead = tmphead->next;
            }
            if(tmphead->next == NULL){
                tmphead->next = chead;
                chead->next = NULL;
            }
        }
        return newhead->next;
    }
};
