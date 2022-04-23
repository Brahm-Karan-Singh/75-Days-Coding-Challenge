class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int start = 0;
        int mid = 0;
        int end = nums.size()-1;
        
        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums[start], nums[mid]);
                mid++;
                start++;
            }
            else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid], nums[end]);
                end -- ;
            }
        }
    }
};