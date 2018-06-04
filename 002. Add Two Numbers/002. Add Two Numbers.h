/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Time complexity: O(max(M,N)); Space complexity: O(max(M,N))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode pre(0);
        ListNode* phead = &pre;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;            
            carry = sum/10;
            phead->next = new ListNode(sum%10);
            phead = phead->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return pre.next;
        //Pay attention to this. When using members by ListNode, use".val" or ".next".
        //When using members by ListNode*(Pointer), use "->val", just as "*().val".
    }
};
