/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/

//Find the mid node of the list.
//Reverse the left par of the list.
//Recombine the left and right parts.
//Time complexity: O(N); Space complexity: O(1)
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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head==NULL||head->next==NULL)
            return;
        while(slow&&fast&&fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* premid = slow;
        ListNode* precurr = slow->next;
        while(precurr->next){
            ListNode* curr = precurr->next;
            precurr->next = curr->next;
            curr->next = slow->next;
            slow->next = curr;
        }
        fast = head;
        slow = slow->next;
        while(fast != premid){
            premid->next = slow->next;
            slow->next = fast->next;
            fast->next = slow;
            fast = slow->next;
            slow = premid->next;
        }
    }
};

//Use a vector to store the node in order to save the relative locaion of these nodes.
//Time complexity: O(N); Space complexity: O(N)
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;
        
        vector<ListNode*> nodes;
        ListNode* iter = head;
        while(iter != NULL)
        {
            nodes.push_back(iter);
            iter = iter->next;
        }
        
        int LEN = nodes.size();
        int left = 0;
        int right = LEN -1;
        while(left < right)
        {
            nodes[left]->next = nodes[right];
            nodes[right--]->next = nodes[++left];
        }
        nodes[left]->next = NULL;
    }
};
