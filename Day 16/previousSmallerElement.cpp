/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
// 	stack for processing  
    stack<int> myStack;
// 	the answer array 
	vector<int> ans(n);
// 	pushing -1 so for elements not having lesser element will return -1
	myStack.push(-1);
	
	for(int i = 0;i<n;i++){
		int curr = arr[i];
		while(myStack.top() >= curr ){
// 			popping the larger element than curr until we find smaller
			myStack.pop();
		}
		
// 		Here we know that top of our stack will be the smaller element than curr
		ans[i] = myStack.top();
// 		pushing the current to stack for next processing 
		myStack.push(curr);
	}
	
// 	returning the resultant answer
	return ans;
}

int main()
{
    vector<int> a = {2,1,4,3};
    vector<int> ans;
    int n = 4;
    ans = nextSmallerElement(a , n);
    for(int i:ans){
        cout<<i<<" ";
    }
    
    

}
