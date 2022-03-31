class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int difference = INT_MAX,returnableSum = 0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1,k = nums.size()-1;
            
            while(j<k){
                
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target)
                    j++;
                else
                    k--;
                
                int dif = abs(target - sum);
                if(dif<difference){
                    returnableSum = sum;
                    difference = dif;
                }    
            }
        
        }
        
        return returnableSum;
    }
};