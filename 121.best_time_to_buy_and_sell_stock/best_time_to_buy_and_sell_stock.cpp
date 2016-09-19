class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int res = 0;
        for (auto price: prices) {
            min_price = min(min_price, price);
            res = max(res, price - min_price);
        }
        return res;
    }
};
