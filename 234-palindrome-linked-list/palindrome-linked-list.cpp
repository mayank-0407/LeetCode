/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseNode(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseNode(head->next);
        ListNode* front = head->next;
        front -> next = head;
        head->next = NULL;
        return newHead; 
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = reverseNode(slow);
        ListNode *head1 = head, *head2 = newHead;

        while(head2){
            if(head1->val != head2->val){
                reverseNode(newHead);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        reverseNode(newHead);

        return true;
    }
};