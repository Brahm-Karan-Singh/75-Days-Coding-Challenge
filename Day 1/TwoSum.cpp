/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Have complexity O(n^2)
//         int counter = 0;
//         vector<int> ans;
        
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 // cout<<nums[i]<<" "<<nums[j]<<" "<<endl;
//                 if((nums[i] + nums[j]) == target){
//                     counter = 1;
//                     ans.push_back(i);                    
//                     ans.push_back(j);
//                     break;
//                 }
               
//             }
//             if(counter == 1)
//                 break;
//         }
//         return ans;
        
        // Only for sorted arrays
//         vector<int> ans;
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         int j = nums.size() - 1;
        
//         while(i<j){
//             if(nums[i] + nums[j] == target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 break;
//             }else if(nums[i] + nums[j] > target){
//                 j--;
//             }else{
//                 i++;
//             }
//         }
        
//         return ans;
    }
};
