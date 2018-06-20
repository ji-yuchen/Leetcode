/*
https://leetcode.com/submissions/detail/159845002/
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?
*/

//Follow the idea of the question"Linked List Cycle", finding if there exists a loop in the list. Then calculate the perimeter of the circle.
//After getting the perimeter, initialize two pointers at the head and move the fast one "perimeter" steps forward. Then ask the fast and slow pointers to move together. They will meet at the start point of the circle.


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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(1){
            if(fast==NULL||fast->next==NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        int numofcircle = 1;
        fast = fast->next;
        while(fast != slow){
            fast = fast->next;
            ++numofcircle;
        }
        fast = head;
        slow = head;
        for(int i=0; i<numofcircle; ++i){
            fast = fast->next;
        }
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        
    }
};
