class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyTell = 0;
        int diff = 0;
        int buy = 0;
        int totalProfit = 0;
        
        for(int i=0;i<prices.size() - 1;i++){
            
            if(buyTell == 0){
                
               if(prices[i] < prices[i+1]){
                   buy = prices[i];
                   buyTell = 1;
               }
                
            }else{
                if(prices[i] > prices[i+1]){
                    diff = prices[i] - buy;
                    totalProfit += diff;
                    buyTell = 0;
                }
            }
            
        }
        
        if(buyTell == 1){
            diff = prices[prices.size()-1] - buy;
            totalProfit += diff;
        } 
        
        return totalProfit;
    }
};