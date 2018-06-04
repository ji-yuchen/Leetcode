/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ...1->3->4->5...
// 
//    ------>
// ...1  3->4->5...
// 
//    ------>
// ...1  3  4->5...
//       ------>
//    ------>
// ...1  3<-4  5...
//       ------>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead(-1);
        ListNode* pre = &prehead;
        pre->next = head;
        while(pre->next != NULL && pre->next->next != NULL){
            ListNode* first = pre->next;
            pre->next = first->next;
            first->next = first->next->next;
            pre->next->next = first;
            pre = first;
        }
        return prehead.next;
    }
};
