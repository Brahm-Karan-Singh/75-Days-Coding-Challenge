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
    ListNode* middleNode(ListNode* head) {
        // Approach 1-
//         int size = 0;
//         ListNode* temp = head;
        
//         while(temp != NULL){
//             size++;
//             temp = temp -> next;
//         }
        
//         int k = (size/2) + 1;
//         size = 1;
//         temp = head;
        
//         while(size != k){
//             temp = temp -> next;
//             size++ ;
//         }
        
//         return temp;
        
        // Approach 2 ->
        
        ListNode* fast = head -> next;
        ListNode* slow = head;
        
        while(fast != NULL && slow != NULL){
            
            fast = fast -> next;
            if(fast != NULL)
                fast = fast -> next;
            slow = slow -> next;
            
        }
        
        return slow;
        
        
        
        
        
        
    }
};