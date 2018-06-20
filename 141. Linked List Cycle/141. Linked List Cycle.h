/*
https://leetcode.com/problems/linked-list-cycle/description/

Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
*/

//use two points. one moves two steps forward while another one moves one step. two points must  meet if there exists a circle.

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
    bool hasCycle(ListNode *head) {
        ListNode* first = head;
        ListNode*second = head;
        while(first != NULL&&first->next!=NULL){
            first = first->next->next;
            second = second->next;
            if(first==second)
                return true;
        }
        return false;
    }
};
