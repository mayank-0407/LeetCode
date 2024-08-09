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
        if(head->next == NULL) return head;

        ListNode* newHead = reverseNode(head->next);
        ListNode* front = head->next;
        front -> next = head;
        head->next = NULL;
        return newHead; 
    }

    ListNode* findKth(ListNode* head, int k){
        k--;
        while(head!=NULL && k>0){
            k--;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tempHead = head;
        ListNode* prevNode = NULL;

        while(tempHead != NULL){
            ListNode* kthNode = findKth(tempHead, k);

            if(kthNode == NULL){
                if(prevNode){
                    prevNode -> next = tempHead;
                }
                break;
            }

            ListNode* nextNode = kthNode -> next;
            kthNode -> next = NULL;
            reverseNode(tempHead);

            if(tempHead == head){
                head = kthNode;
            }else{
                prevNode -> next = kthNode;
            }

            prevNode = tempHead;
            tempHead = nextNode;
        }
        return head;
    }
};