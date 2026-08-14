class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=0;
        int maximum=0;
        int profit=0;
        for (int i=1;i<prices.size();i++) {
            if (prices[min] > prices[i]) {
                min = i;
                maximum = i;
            }
            if (prices[maximum] < prices[i]) {
                maximum=i;
                profit = max(profit, prices[maximum] - prices[min]);
            }
        }
        return profit;
    }
};
