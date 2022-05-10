/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    
    
};

// Getting size of linked list
int getSize(Node* head){;
    Node* temp = head;
    int size = 0;
        
    while(temp != NULL){
        size++;
        temp = temp -> next;
    }
    return size;
}

// Inserting at head of linked list 
void insertAtHead(Node* &head, int elem){
    Node* t = new Node(elem);
    t -> next = head;
    head = t;
}


class Stack{
    
    Node* head;
    int size;
    
    public:
    Stack(int s){
        size = s;
        head = NULL;
    }
    
    
    // Push function 
    void push(int elem){
        if(getSize(head) < size){
            insertAtHead(head, elem);
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }
    
    // Pop function
    void pop(){
        if(head != NULL){
            Node* temp = head;
            head = head -> next;
            delete temp;
        }

        else
            cout<<"Stack underflow"<<endl;
    }
    
    // Empty function 
    bool isEmpty(){
        if(head == NULL)
            return true;
        else
            return false;
    }
    
    // Peek function 
    int peek(){
        if(head != NULL)
            return head -> data;
        else{
            return -1;
        }
    }
    
    // Print function 
     void print(){
        if(head == NULL){
            cout<<"There is nothing to print in a stack"<<endl;
            return ;
        }
        Node* temp = head;
        while(temp != NULL){
            cout<<temp -> data <<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
    
    
    
};

int main()
{
    Stack *st = new Stack(4);
    st -> push(2);
    st -> push(3);
    st -> print();
    st -> pop();
    st -> pop();
    cout<<"Peek element is: "<<st -> peek()<<endl;
    if(st -> isEmpty())
        cout<<"IS empty returned true: "<<st-> isEmpty()<<endl;
    else
        cout<<"IS empty returned false: "<<st-> isEmpty()<<endl;
    st -> print();
    return 0;
}
