#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
// 	stack for processing  
    stack<int> myStack;
// 	the answer array 
	vector<int> ans(n);
// 	pushing -1 so for elements not having lesser element will return -1
	myStack.push(-1);
	
	for(int i = n-1;i>=0;i--){
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