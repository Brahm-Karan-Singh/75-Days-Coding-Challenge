class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int decrementer = 0;
        int addOneCarry = 0;
        int lastElement = digits.size() -1;
        
        while(decrementer < digits.size()){
        
        if(digits[lastElement-decrementer] == 9){
            digits[lastElement-decrementer] = 0;
            addOneCarry = 1;
            decrementer ++ ;
        }else{
            addOneCarry = 0;
            digits[lastElement-decrementer]++ ;
            break;
        }
        
      }
        if(addOneCarry)
            digits.insert(digits.begin(),1);
        
     return digits;
        
    }
};