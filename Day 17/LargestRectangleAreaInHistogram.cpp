class Solution {
private:
    void nextSmall(vector<int> heights , vector<int> &arr , int n){
        stack<int> s;
        s.push(-1);
         for(int i = n-1 ; i>=0; i--){
             while(s.top()!=-1 && heights[s.top()] >= heights[i]){
                 s.pop();
             }
             
             arr[i] = s.top();
             s.push(i);
         }
    }
    void prevSmall(vector<int> heights , vector<int> &arr , int n){
        stack<int> s;
        s.push(-1);
         for(int i = 0 ; i<n; i++){
             while(s.top() != -1 && heights[s.top()] >= heights[i]){
                 s.pop();
             }
             arr[i] = s.top();
             s.push(i);
         }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        int ans = 0;
        
        // Called a function to get all the nextSmaller elements
        nextSmall(heights ,rightSmall , n);
        prevSmall(heights, leftSmall , n);
        
        for(int i = 0; i < n;i++ ){
            if(rightSmall[i] == -1) 
                rightSmall[i] = heights.size();
            
            int area = heights[i] * (rightSmall[i] - leftSmall[i] - 1);
            ans = max(area , ans);
        }
        return ans;
    }
};