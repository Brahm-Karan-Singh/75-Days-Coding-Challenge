bool isValidParenthesis(string expression)
{
    stack<char> s;
	for(int i= 0 ;i< expression.length();i++){
		char ch = expression[i];
// 		check whether it is opening or not
		if(ch == '(' || ch == '[' || ch == '{')
			s.push(ch);
		else{
			if(!s.empty()){
				char temp = s.top();
				if((ch == ')' && temp == '(' ) ||
				   (ch == ']' && temp == '[') ||
				   (ch == '}' && temp == '{')){
					s.pop();
				}
				else
					return false;
			}
			else
				return false;
		}
	}
	if(s.empty())
		return true;
	else
		return false;
}