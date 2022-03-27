class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int element = nums[0];
        int i = 1;
        while(i<nums.size()){
            if(nums[i] == element){
                nums.erase(nums.begin() + i);
            }else{
                element = nums[i];
                i++;
            }   
        }
        
        return nums.size();
    }
};