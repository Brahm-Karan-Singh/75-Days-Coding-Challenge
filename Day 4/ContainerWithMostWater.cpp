class Solution {
public:
    int maxArea(vector<int>& height) {
        int ansMax = INT_MIN, i = 0,j = height.size()-1,minOfBoth;
        int lengthOfContainer;
        
        while(i<j){
            
            minOfBoth = min(height[i],height[j]);
            lengthOfContainer = j - i;
            int area = minOfBoth * lengthOfContainer;
            if(ansMax < area)
                ansMax = area;
            
            if(height[i]>height[j])
                j--;
            else
                i++;
                
        }
        
        return ansMax;
    }
};