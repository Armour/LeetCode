class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res;
        vector<int> index(primes.size(), 0);
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
