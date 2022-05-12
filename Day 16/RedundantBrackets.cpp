#include<stack>
bool findRedundantBrackets(string &s)
{
    stack<char> myStack;
	for(int i = 0; i< s.length(); i++){
		if(s[i] == '(' || s[i] == '+' || 
		   s[i] == '-' || s[i] == '*' || s[i] == '/'){
			myStack.push(s[i]);
		}
		else if(s[i] == ')'){
// 			check until '(' bracket is found
			bool isRedundant = true;
			while(myStack.top() != '('){
				char temp = myStack.top();
				if( temp == '+' || temp == '-' || temp == '*' || temp == '/'){
					isRedundant = false;
				}
				myStack.pop();
			}
			if(isRedundant)
				return true;
			myStack.pop();
		}
	}
	
	return false;
	
}
