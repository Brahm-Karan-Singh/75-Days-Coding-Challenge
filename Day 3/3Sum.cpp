class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
         
     vector<vector<int>> result;
        
    if(a.size() == 0 || a.size() == 1 || a.size() == 2)
        return result;
        
        
        sort(a.begin(),a.end());
        int prevI = INT_MIN;
        
        for(int i=0;i< a.size()-2 ;i++){
            int j = i+1,sum = 0- a[i];
            int k = a.size()-1;
            
            if(prevI == a[i]){
                continue;
            }
                
            
            while(j<k){
                if(a[j]+ a[k] == sum){
                    vector<int> triplet;
                    triplet.push_back(a[i]);
                    triplet.push_back(a[j]);
                    triplet.push_back(a[k]);
                    result.push_back(triplet);
                
                    int storeJ = a[j++];
                    int storeK = a[k--];
                    
                   
                    
                    while(j<k && (a[j] == storeJ)) j++;
                    while(j<k && (a[k] == storeK)) k--;
                    
                }
                
                else if(a[j]+ a[k] > sum)
                    k--;
                else
                    j++;
                
            }
            
            prevI = a[i];
            
        }  
        return result;
    }
};