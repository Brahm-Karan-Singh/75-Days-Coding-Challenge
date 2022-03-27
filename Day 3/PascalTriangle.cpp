class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> latestArray = {1};
        vector<int> tempArray;
        ans.push_back({1});
        
        if(numRows == 1)
            return ans;
        
        for(int i=1;i<numRows; i++){
            tempArray.push_back(1);
            
            int n = latestArray.size();
            // Kuj operations
            for(int i=0;i<n-1;i++){
                tempArray.push_back(latestArray[i] + latestArray[i+1]);
            }
            
            tempArray.push_back(1);
            latestArray = tempArray;
            ans.push_back(latestArray);
            tempArray.clear();
            
        }
        
        return ans;
    }
};