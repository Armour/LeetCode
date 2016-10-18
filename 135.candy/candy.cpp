class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) return 0;
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = max(candies[i], candies[i - 1] + 1);
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
