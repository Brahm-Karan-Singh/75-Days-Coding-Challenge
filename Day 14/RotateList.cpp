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
    ListNode* rotateRight(ListNode* head, int k) {
//         for(int i = 0; i<k; i++){
//             if(head == NULL)
//                 return NULL;
//             if(head -> next == NULL)
//                 return head;
            
            // // Code for rotation
            // ListNode* temp = head -> next;
            // while(temp != NULL){
            //  int tempVal = head -> val;
            //  head -> val = temp -> val;
            //  temp -> val = tempVal;  
            //  temp = temp -> next;
            // }
//         }
        
//         return head;
        
        if(head == NULL)
            return NULL;
        if(head -> next == NULL)
            return head;
        
        int size = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            size++;
            temp = temp -> next;
        }
        
        int number = k%size;
        
        for(int i=0; i<number; i++){
             // Code for rotation
            temp = head -> next;
            while(temp != NULL){
             int tempVal = head -> val;
             head -> val = temp -> val;
             temp -> val = tempVal;  
             temp = temp -> next;
            }
        }
        
        return head;      
            
    }
};