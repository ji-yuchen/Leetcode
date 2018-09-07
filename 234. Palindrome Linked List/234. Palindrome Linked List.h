/*
https://leetcode.com/problems/palindrome-linked-list/description/

Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //Find the mid node of the list. Then, reverse the second part. Compare the first and the second part node by node.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow, *fast;
        slow = fast = head;
        ListNode* prevslow, *mid;
        ListNode* second;
        while(fast && fast->next) {
            prevslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prevslow->next = NULL;
        if(fast && fast->next == NULL) {
            mid = slow;
            slow = slow->next;
        }
        
        second = reverseList(slow);
        bool ans;
        while(head && second) {
            if(head->val != second->val) {
                return false;
            }
            head = head->next;
            second = second->next; 
        }
        
        return true;
        
    }
    
    
    ListNode* reverseList(ListNode* head) {
        ListNode* next, *prev, *curr;
        curr = head;
        prev = NULL;
        next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    
};
