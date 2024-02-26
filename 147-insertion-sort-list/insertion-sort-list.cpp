class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode revHead(std::numeric_limits<int>::max(), nullptr);
        ListNode* insert = head;
        while (insert != nullptr) {
            int val = insert->val;
            ListNode* insertBehind = &revHead;
            while (insertBehind->next != nullptr && insertBehind->next->val > val) {
                insertBehind = insertBehind->next;
            }

            ListNode* nextInsert = insert->next;
            insert->next = insertBehind->next;
            insertBehind->next = insert;
            insert = nextInsert;
        }

        ListNode* prev = nullptr;
        ListNode* curr = revHead.next;
        while (true) {
            ListNode* next = curr->next;
            if (next == nullptr) {
                curr->next = prev;
                return curr; 
            } else {
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        }

        return nullptr;
    }
};