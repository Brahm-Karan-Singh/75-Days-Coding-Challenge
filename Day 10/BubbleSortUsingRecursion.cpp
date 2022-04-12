/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void bubbleSort(int* arr,int n){
    // base case

    if(n == 0 || n == 1)
        return;
    
    for(int i=0 ; i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    
    bubbleSort(arr,n-1);
}

int main()
{
   int arr[] = {1,-42,2,7,4,9,5};
   int n = sizeof(arr)/sizeof(arr[0]);
   bubbleSort(arr,n);
   
   for(int i = 0;i<n;i++){
       cout<<arr[i]<<" ";
   }

    return 0;
}
