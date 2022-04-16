
class Solution
{
    private:
    Node* reverseList(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
    void insertAtTail(Node* &tail, int value){
        Node* a = new Node(value);
        tail -> next = a;
        tail = a;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // Reverse the lists for addition
        Node* firstReversed = reverseList(first);
        Node* secondReversed = reverseList(second);
        // Answer list 
        Node* ansHead = new Node(-1);
        Node* ansTail = ansHead;
        
        int carry = 0;
        while(firstReversed != NULL || secondReversed!= NULL){
            int value;
            // Finding the sum and carry 
            if(firstReversed != NULL && secondReversed != NULL)
                value = firstReversed -> data + secondReversed -> data + carry;
            if(firstReversed == NULL)
                value = secondReversed -> data + carry;
            if(secondReversed == NULL)
                value = firstReversed -> data + carry;
                
            // Checking for the carry 
            if(value >= 10){
                carry = 1;
                value = value % 10;
            }else{
                carry = 0;
            }
            
            // Inserting the value
            insertAtTail(ansTail,value);
            
            // Incrementing the pointer
            if(firstReversed != NULL)
                firstReversed = firstReversed -> next;
            if(secondReversed != NULL)
                secondReversed = secondReversed -> next;
         
        }
        
        if(carry == 1){
            insertAtTail(ansTail,1);
        }
        
        Node* head = reverseList(ansHead -> next);
        delete ansHead;
        return head;
    }
};
