/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head->next == NULL) return false;
        std::vector<ListNode*> ptr{};
        ListNode *ele = head;
        while(ele->next != NULL){
            for (vector<ListNode*>::iterator iter = ptr.begin(); iter != ptr.end(); ++iter){
                if (ele->next == *iter){
                    return true;
                }
            }
            ptr.push_back(ele->next);
            ele = ele->next;
        }
        return false;
    }
};
// @lc code=end

