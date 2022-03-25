class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n-1;i++){
            if(nums[i] == 0){
                for(int j=i+1;j<n;j++){
                    if(nums[j] != 0){
                        // Do the Swapping 
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
            }
        }
    }
};