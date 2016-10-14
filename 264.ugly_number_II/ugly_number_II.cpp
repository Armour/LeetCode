class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        vector<int> primes = {2, 3, 5};
        vector<int> index = {0, 0, 0};
        res.push_back(1);
        for (int i = 2; i <= n; i++) {
            int ugly = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                ugly = min(ugly, primes[j] * res[index[j]]);
            }
            for (int j = 0; j < primes.size(); j++) {
                if (ugly == primes[j] * res[index[j]]) {
                    index[j]++;
                }
            }
            res.push_back(ugly);
        }
        return res[n - 1];
    }
};
