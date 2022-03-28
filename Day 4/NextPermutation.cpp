class Solution {
public:
   
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPointIndex,i;
        
        for(i= n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakPointIndex = i;
                break;
            }
        }
        
        if(i>=0){
            
            for(i = n-1;i>breakPointIndex;i--){
                if(nums[i]>nums[breakPointIndex]){
                   swap(nums[i],nums[breakPointIndex]);
                   reverse(nums.begin()+breakPointIndex+1,nums.end());
                    break;
                }
         }
            
        }
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};