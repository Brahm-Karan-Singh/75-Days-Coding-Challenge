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
    
    ListNode* solve(ListNode* list1, ListNode* list2){
        
        // For only one element
        if(list1 -> next == NULL){
            list1 -> next = list2;
            return list1;
        }
        
        // Making some pointers for solution
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* next1 = list1 -> next;
        ListNode* next2 = NULL;
        
        // Merging the lists
        while(next1 != NULL && curr2 != NULL){
        if((curr2 -> val >= curr1 -> val) && (curr2 -> val <= next1 -> val)){
            
           next2 = curr2 -> next;
           curr1 -> next = curr2;
           curr2 -> next = next1;
           curr1 = curr1 -> next;
           curr2 = next2;
            
        }else{
            
            curr1 = curr1 -> next;
            next1 = next1 -> next;
            
            if(next1 == NULL){
                curr1 -> next = curr2;
                return list1;
            }
            
        }
    }
        
        return list1;
        
        
        
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        // Deciding whom to take first and second list 
        if(list1 -> val <= list2 -> val){
            return solve(list1, list2);
        }else{
            return solve(list2, list1);
        }
    }
};