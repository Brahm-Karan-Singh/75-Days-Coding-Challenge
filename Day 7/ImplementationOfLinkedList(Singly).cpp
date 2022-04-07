#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node(){
        // Freeing the memory 
        if(this->next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
      
};

// We are using & with head as we want to make changes to the original 
// linked list if we are not using & then it will create copy and the changes will
// not be effected in the same list

void insertAtHead(Node* &head,int data){
    Node* n = new Node(data);
    n -> next = head;
    head = n;
}

void insertAtTail(Node* &tail,int data){
    Node* n = new Node(data);
    tail -> next = n;
    tail = tail -> next;
}

void insertAtPosition(Node* tail,Node* &head,int position,int data){
    // if to insert at start then handling the case 
    if(position ==  1){
        insertAtHead(head, data);
        return ;
    }
    
    Node* temp = head;
    int count = 1;
    
    while(count < position - 1){
        temp = temp -> next;
        count++ ;
    }
    
    // If the position is last then handling that case
    
    if(temp -> next == NULL){
        insertAtTail(tail,data);
        return;
    }
    
    Node* n = new Node(data);
    n -> next = temp -> next;
    temp -> next = n;
}

// Deletion code starts from here 
void deleteAtPosition(int position,Node* &head,Node* &tail){
    
    Node* curr = head;
    Node* prev = NULL;
    int count = 1;
    
    if(position == 1){
        Node* temp = head;
        head = head -> next;
         // Making the next of deleting node to point to null as we don't want to delete whole list
        temp ->next = NULL;
        delete temp;
        return;
    }
    
    while(count < position){
        prev = curr;
        curr = curr -> next;
        count ++;
    }
    
    prev -> next = curr -> next;
    // Making the next of deleting node to point to null as we don't want to delete whole list
    curr -> next = NULL;
    delete curr;
    if(prev -> next == NULL){
        tail  = prev;
    }
    
    
}


// Traversing and printing 

void print(Node* &head){
    Node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}


int main()
{
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
    
    insertAtTail(tail,12);
    insertAtTail(tail,14);
    insertAtPosition(tail,head,2,13);
    insertAtPosition(tail,head,2,18);
    cout<<"The position of tail is "<<tail->data<<endl;
    cout<<"The position of head is "<<head->data<<endl;
    print(head);
    deleteAtPosition(5,head,tail);
    print(head);
    cout<<"The position of tail is "<<tail->data<<endl;
    cout<<"The position of head is "<<head->data<<endl;
    

    return 0;
}
