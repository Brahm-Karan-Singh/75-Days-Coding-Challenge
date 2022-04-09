/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// Implementing doubly linked list Circular one 

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
    
    ~Node(){
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};

void insertAtNode(Node* &tail, int value, int element){

    // Empty list 
    if(tail == NULL){
        Node* temp = new Node(value);
        temp -> next = temp;
        temp -> prev = temp;
        tail = temp;
    }else{
        
        // assuming the element is present in the LL
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        
        Node* temp = new Node(value);
        temp -> next = curr -> next;
        curr -> next = temp;
        temp -> prev = curr;
        curr -> next -> prev = temp;
        
        
    }
    
}

void print(Node* tail){
    
    if(tail == NULL){
        cout<<"Your linked list is empty "<<endl;
        return;
    }else{
        Node* temp = tail;
        do{
            cout<<temp -> data<< " ";
            temp = temp -> next;
        }while(temp != tail);
        
    }
    cout<<endl;
    
}


void deleteNode(Node* &tail, int value){
    Node* last = tail;
    Node* curr = tail -> next;
    if(tail == NULL){
        cout<<"Your list is already empty "<<endl;
        return;
    }
    
    else if(curr == last){
        tail = NULL;
        cout<<"Your list is empty"<<endl;
        return ;
    }
    
    else{
        
        // assuming element is present in the ll
        while(curr -> data != value){
            last = curr;
            curr = curr -> next;
        }
        
        last -> next = curr -> next;
        curr -> next -> prev = last;
        curr -> next = NULL;
        curr -> prev = NULL;
        
        // checking whether tail is not deleted with curr as it will generate error while printing 
        if(tail == curr){
            tail = last;
        }
        
        delete curr;
    }
}



int main()
{
   Node* tail = NULL;
   
   insertAtNode(tail,3 ,4);
   print(tail);
   
   insertAtNode(tail,5 ,3);
   print(tail);
   
   insertAtNode(tail,4 ,3);
   print(tail);
   
   insertAtNode(tail,7 ,5);
   print(tail);
   
   deleteNode(tail, 7);
   print(tail);
   
    return 0;
}
