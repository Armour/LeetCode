class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int buy1 = INT_MIN;
        int sell1 = INT_MIN;
        int buy2 = INT_MIN;
        int sell2 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            if (buy2 != INT_MIN) sell2 = max(sell2, buy2 + prices[i]);
            if (sell1 != INT_MIN) buy2 = max(buy2, sell1 - prices[i]);
            if (buy1 != INT_MIN) sell1 = max(sell1, buy1 + prices[i]);
            buy1 = max(buy1, -prices[i]);
        } 
        if (sell2 != INT_MIN)
            return max(0, max(sell1, sell2));
        else
            return max(sell1, 0);
    }
};
