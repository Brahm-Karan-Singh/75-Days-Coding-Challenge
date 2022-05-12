void inSortedWay(stack<int> &stack , int num){
// 	base case
	if(stack.empty() || (!stack.empty() && stack.top() < num)){
		stack.push(num);
		return ;
	}
	
	int elem = stack.top();
	stack.pop();
	
	inSortedWay(stack , num);
	stack.push(elem);
	
}

void sortStack(stack<int> &stack)
{
	// base case
	if(stack.empty())
		return ;
	int num = stack.top();
	stack.pop();
	
	sortStack(stack);
	inSortedWay(stack , num);
}