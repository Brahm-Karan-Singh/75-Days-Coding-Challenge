/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void sayDigits(int n){
    
    // base case
    if(n == 0)
        return ;
      
    int temp = n % 10;  
    sayDigits(n/10);
    
    switch(temp){
        case 0 :cout<<"Zero";
                break;
        case 1 :cout<<"One ";
                break;
        case 2 :cout<<"Two ";
                break;
        case 3 :cout<<"Three ";
                break;
        case 4 :cout<<"Four ";
                break;
        case 5 :cout<<"Five ";
                break;
        case 6 :cout<<"Six ";
                break;
        case 7 :cout<<"Seven ";
                break;
        case 8 :cout<<"Eight ";
                break;
        case 9 :cout<<"Nine ";
                break;
       
    }
    
}

int main()
{

    int n;
    cout<<"Enter any number "<<endl;
    cin>>n;
    
    sayDigits(n);
   
    return 0;
}
