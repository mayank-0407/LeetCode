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
    ListNode *lento = head;
    ListNode *rapdio = head;
 
    while (rapdio != nullptr && rapdio->next != nullptr) {
        lento = lento->next;
        rapdio = rapdio->next->next;
    
        if (lento == rapdio) {
            lento = head;
        while (lento != rapdio) {
            lento = lento->next;
            rapdio = rapdio->next;
        } 
        return lento;
      }
    }
    return nullptr;
  }
};