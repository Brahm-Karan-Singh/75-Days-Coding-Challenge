#include<vector>
class Solution{
   private:
  Node* reverse(Node* &h){
        
        Node* prev = NULL;
        Node* curr = h;
        Node* forward = NULL;
        
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
       
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
    //     vector<int> arr;
    //     Node* temp = head;
        
    //     while(temp != NULL){
    //         arr.push_back(temp -> data);
    //         temp = temp -> next;
    //     }
        
    //     int i = 0;
    //     int j = arr.size()-1;
        
    //     while(i<j){
    //         if(arr[i] != arr[j])
    //             return false;
    //         i++;j--;
    //     }
        
    //     return true;
    // }
    
  if(head -> next == NULL) return true;
    
    
    // Approach 2-
    // Finding Middle
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next !=NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    // Reversing the list 
    Node* tempo = slow -> next;
    slow -> next = reverse(tempo);
    
    // Checking for palindrome
    Node* head1 = head;
    Node* head2 = slow -> next;
    
    while(head2 != NULL){
        if(head1 -> data != head2 -> data)
            return false;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    return true;
   
    } 
    
};