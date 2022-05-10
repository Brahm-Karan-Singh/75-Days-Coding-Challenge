/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;
    
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    
    // Push function 
    void push(int elem){
        if(top < size - 1){
            top++;
            arr[top] = elem;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }
    
    // Pop function
    void pop(){
        if(top >= 0)
            top--;
        else
            cout<<"Stack underflow"<<endl;
    }
    
    // Empty function 
    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }
    
    // Peek function 
    int peek(){
        if(top >= 0)
            return arr[top];
        else{
            cout<<"Stack is empty from peek"<<endl;
            return -1;
        }
    }
    
    // Print function 
    void print(){
        if(top == -1)
            cout<<"Your stack is empty from print"<<endl;
        else{
            for(int i = 0;i<= top;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
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
    cout<<"Peek element is "<<st -> peek()<<endl;
    if(st -> isEmpty())
        cout<<"IS empty returned true: "<<st-> isEmpty()<<endl;
    else
        cout<<"IS empty returned false: "<<st-> isEmpty()<<endl;
    st -> print();
    return 0;
}
