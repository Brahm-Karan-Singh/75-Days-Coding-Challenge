#include <stack>
#include <cmath>
int findMinimumCost(string str) {
//   step 1 - return false if string is odd 
	if(str.length() % 2 == 1){
		return -1;
	}
	
// 	step 2 -remove all the valid braces from stack
	stack<char> myStack;
	for(int i = 0; i < str.length() ; i++){
		char temp = str[i];
		if(temp == '{')
			myStack.push(temp);
		else{
			if(!myStack.empty() && myStack.top() == '{')
				myStack.pop();
			else
				myStack.push(temp);
		}
	}
	
// 	Now count no of open and closed braces and return the general expression
	int a = 0, b = 0;
	while(!myStack.empty()){
		if(myStack.top() == '{')
			a += 1;
		else
			b += 1;
		myStack.pop();
	}

	
	return (a+1)/2 + (b+1)/2;
}