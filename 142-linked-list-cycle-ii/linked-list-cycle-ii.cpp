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
        ListNode* ptr=head;
        map<ListNode*,int> mpp;
        while(ptr!=NULL){
            if(mpp[ptr]!=0) return ptr;
            mpp[ptr]=1;
            ptr=ptr->next;
        }
        return nullptr;
    }
};