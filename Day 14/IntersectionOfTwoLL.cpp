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
    
    ListNode* getNode(ListNode* large , ListNode* small, int diff){
        
        while(diff != 0 ){
            large = large -> next;
            diff -- ;
        }
        
        while(large != small){
            large = large -> next;
            small = small -> next;
        }
        
        return large;
        
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // First way
        
        // ListNode* a = headA;
        // ListNode* b = headB;
        // int lenA = 0,lenB = 0;
        // while(a!= NULL){
        //     lenA++;
        //     a = a -> next;
        // }
        // while(b!= NULL){
        //     lenB++;
        //     b = b -> next;
        // }
        // a = headA;
        // b = headB;
        // if(lenA > lenB){
        //    return getNode(a,b,(lenA - lenB)); 
        // }else{
        //     return getNode(b,a,(lenB - lenA));   
        // }
        
        // Second way
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a != b){
            // Moving a , if null then starting from other linked list
            if(a == NULL)
                a = headB;
            else
                a = a -> next;
            
            // Moving b, if null then starting from other linked list
            if(b == NULL)
                b = headA;
            else
                b = b -> next;
        }
        
        return a;        
    
    }
};