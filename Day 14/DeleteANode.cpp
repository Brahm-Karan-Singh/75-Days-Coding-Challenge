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
    void deleteNode(ListNode* node) {
        while(node -> next != NULL){
            int data = node -> next -> val;
            node -> val = data;
            if(node -> next -> next == NULL){
                node -> next = NULL;
                return;
            }     
            node = node -> next;
        }
        
    }
};