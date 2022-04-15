#include <iostream>
#include <map>
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

Node* detectLoop(Node* head){
    if(head == NULL)
        return NULL;
    // Approach 1 - Using maps 
    
    // map<Node*,bool> visited;
    // Node* temp = head;
    
    // while(temp != NULL){
    //     if(visited[temp] == true)
    //         return true;
       
    //     visited[temp] = true;
    //     temp = temp -> next;
    // }
    // return false;
    
    // Approach -2 - Floyds Loop Detection algo
    
    Node* fast = head;
    Node* slow = head;
    
    while(slow != NULL && fast != NULL){
        // cout<<"slow = "<<slow -> data<<" fast "<<fast -> data<<endl;
        slow = slow -> next;
        fast = fast -> next;
        if(fast != NULL)
            fast = fast -> next;
        if(slow == fast)
            return slow;
    }
    return NULL;
}

Node* findBeginingNode(Node* head){
    
    if(head == NULL)
        return NULL;
        
    Node* fast = detectLoop(head);
    
    Node* temp = head;
    
    while(temp != fast){
        temp = temp -> next;
        fast = fast -> next;
    }
    return temp;
}

void removeLoop(Node* &head){
    Node* startingNode = findBeginingNode(head);
    if(startingNode == NULL)
        return ;
        
    Node* temp = startingNode;
    
    while(temp -> next != startingNode){
        temp = temp -> next;
    }
    temp -> next = NULL;
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
    deleteAtPosition(5,head,tail);
    print(head);
    // line to create loop in a linked list
    tail -> next = head -> next;
    
    // bool isLoopOccur = detectLoop(head);
    // if(isLoopOccur)
    //     cout<<"There is a loop in the given linked list"<<endl;
    // else
    //     cout<<"There is no loop in the linked list"<<endl;
    
    Node* t = findBeginingNode(head);
    cout<<"The starting of the loop is "<<t->data<<endl;
    
    removeLoop(head);
    cout<<"List after removing loop is "<<endl;
    print(head);
    

    return 0;
}