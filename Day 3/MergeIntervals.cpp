class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<int> prevArray = intervals[0];
        vector<vector<int>> finalAns;
        
        
        if(intervals.size() == 1)
            return intervals;
        
        for(int i=1;i<intervals.size();i++){
            
            if(intervals[i][0] <= prevArray[1]){
                prevArray[0] = min(prevArray[0], intervals[i][0]);
                prevArray[1] = max(prevArray[1], intervals[i][1]);
            }
            
            else{
                finalAns.push_back(prevArray);
                prevArray = intervals[i];
            }
                
        }
        
        finalAns.push_back(prevArray);
        
        return finalAns;
    }
};