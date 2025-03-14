/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
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
        if (head==NULL) return NULL;
        if (head->next==NULL) return NULL;
        vector<ListNode*> node_ptr{};
        node_ptr.push_back(head);
        vector<ListNode*>::iterator iter1 = node_ptr.begin();  
        while(iter1 != node_ptr.end()){
            for (vector<ListNode*>::iterator iter2 = node_ptr.begin(); iter2 != node_ptr.end(); ++iter2){
                if(*iter1->next == *iter2) {
                    return *iter2;
                }
            }
            node_ptr.push_back(*iter1->next);
            ++iter1;
        }
        return NULL;
    }
};

// @lc code=end

