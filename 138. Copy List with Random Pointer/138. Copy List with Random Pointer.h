/*
https://leetcode.com/problems/copy-list-with-random-pointer/description/

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
*/
//The main problem is that, we are not able to deepcopy random pointer directly.
//We can build a copylist based on the original list, copy each listnode and insert the copy node after each listnode.
//So we are able to get the copy node pointed by random pointer.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * head_cp = nullptr, * cur = head, * cur_cp = nullptr;
        if (head == nullptr)
            return nullptr;
        while (cur != nullptr)
        {
            cur_cp = new RandomListNode (cur->label);
            cur_cp->next = cur->next;
            cur->next = cur_cp;
            cur = cur_cp->next;
        }
        cur = head;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            if (cur->random)
                cur_cp->random = cur->random->next;
            cur = cur_cp->next;
        }
        cur = head;
        head_cp = head->next;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            cur->next = cur_cp->next;
            cur = cur->next;
            if (cur)
                cur_cp->next = cur->next;
        }
        return head_cp;
    }
};


//Also, we can use a hashmap to record the order of original list.\
//Time complexity： O(N); Space complexity: O(N)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> old2new;
        RandomListNode* dummy = new RandomListNode(-1);
        RandomListNode* tmp = head;
        RandomListNode* curr = dummy;
        while(tmp){
            RandomListNode* newNode = new RandomListNode(tmp->label);
            old2new[tmp] = newNode;
            curr->next = newNode;
            curr = curr->next;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            if(tmp->random){
                old2new[tmp]->random = old2new[tmp->random];
            }
            tmp = tmp->next;
        }
        return dummy->next;
    }
};
