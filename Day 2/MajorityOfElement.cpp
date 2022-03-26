class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Boyer Moore algorithm 
        int ansIndex = 0;
        int n = nums.size();
        int count = 1;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[ansIndex])
                count++;
            else
                count--;
            
            if(count == 0){
                ansIndex = i;
                count = 1;
            }
        }
        
        // Now make sure the element is in majority 
        int number = nums[ansIndex];
        count = 0;
        
        for(int i=0;i<n;i++){
            if(number == nums[i])
                count++;
        }
        
        if(count>(nums.size()/2))
            return number;
        else
            return 0;
    }
};