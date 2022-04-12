void reverseString(string& str, int i , int j,int n){
    
//     base case
       if(i>j)
           	return ;
    	char temp = str[i];
    	str[i] = str[j];
    	str[j] = temp;
//     	recursive call 
		i++;
    	reverseString(str , i , n-i-1,n);
}

string reverseString(string str)
{
	int i = 0;
	int n = str.length();
    reverseString(str,i,n-1,n);
    return str;
}