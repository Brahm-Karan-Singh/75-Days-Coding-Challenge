/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* n = new Node(data); 
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail -> next = n;
            tail = n;
        }
    
    }
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)
            return NULL;
        
        // Approach 1 -  Using maps 
        
        // step 1 -> create clone list with next pointers 
//         Node* cloneHead = NULL;
//         Node* cloneTail = NULL;
//         Node* temp = head;
        
//         while(temp != NULL){
//             insertAtTail(cloneHead, cloneTail, temp->val);
//             temp = temp -> next;
//         }
        
        // step 2 -> create map with maping of original nodes to clone nodes
        
        // unordered_map<Node*,Node*> mapping;
        // temp = head;
        // Node* tempClone = cloneHead;
        // while(temp != NULL){
        //     mapping[temp] = tempClone;
        //     temp = temp -> next;
        //     tempClone = tempClone -> next;
        // }
        
        // step 3 -> arrange the random pointers
        
        // temp = head;
        // tempClone = cloneHead;
        // while(temp != NULL){
        //     tempClone -> random = mapping[temp -> random];
        //     temp = temp -> next;
        //     tempClone = tempClone -> next;
        // }
        
//         return cloneHead;
        
        
        
        // Approach 2 - without map and changing the links instead
        
         
        // step 1 -> create clone list with next pointers 
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }
        
        // step 2 -> insert the clone Nodes in between original nodes
        temp = head;
        Node* cloneTemp = cloneHead;
        
        while(temp != NULL){

            Node* nextNode = temp -> next;
            temp -> next = cloneTemp;
            temp = nextNode;
            
            nextNode = cloneTemp -> next;
            cloneTemp -> next = temp;
            cloneTemp = nextNode;
           
        }
        
        // step3 - fix the random pointers of the cloneNode
        temp = head;
        
        while(temp != NULL){
            if(temp -> random != NULL)
                temp -> next -> random = temp -> random -> next;
            else
                temp -> next -> random = NULL;
            temp = temp -> next -> next;
        }
        
        // step 4 - revert the pointers to original after the work 
        
        temp = head;
        cloneTemp = cloneHead;
        
        while(temp != NULL){
            temp -> next = cloneTemp -> next;
            temp = temp -> next;
            
            if(temp != NULL)
                cloneTemp -> next = temp -> next;
            cloneTemp = cloneTemp -> next;
        }
        
        
        // step 5 -return the head pointer of the clone list 
        return cloneHead;
            
            
            
            
            
            
            
        
    }
};