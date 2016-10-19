class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (int c: nums) {
            int n_a = (a & ~b & ~c) | (~a & b & c);
            int n_b = (~a & b & ~c) | (~a & ~b & c);
            a = n_a;
            b = n_b;
        }
        return a | b;
    }
};
