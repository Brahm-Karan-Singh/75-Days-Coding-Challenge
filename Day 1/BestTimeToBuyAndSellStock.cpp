

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int profit = 0;
        int buy = a[0];
        
        for(int i=1;i<a.size();i++){
            int difference = a[i] - buy;
            buy = min(buy,a[i]);
            profit = max(profit,difference);
        }
        return profit;
    }
};