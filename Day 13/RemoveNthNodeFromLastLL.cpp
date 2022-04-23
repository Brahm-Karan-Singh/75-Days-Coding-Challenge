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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Brute Force Approach
//         int size = 0;
//         ListNode* temp = head;
//         while(temp != NULL){
//             size++;
//             temp = temp -> next;
//         }
        
//         int k = size - n;
//         if(k == 0)
//             return head -> next;
        
//         size = 1;
//         temp = head;
//         while(size != k){
//             temp = temp -> next;
//             size++;
//         }
        
//         ListNode* forward = temp -> next;
//         temp -> next = forward -> next;
//         forward -> next = NULL;
//         delete forward;
        
//         return head;
        
        // Approach 2 -
        if(head == NULL)
            return NULL;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        int size = n;
        
        while(size != 0){
            fast = fast -> next;
            size --;
        }
        
        while(fast -> next != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        
        ListNode* temp = slow -> next;
        slow -> next  = temp -> next;
        temp -> next = NULL;
        delete temp;
        
        head = dummy -> next;
        return head;
        
        
    }
};