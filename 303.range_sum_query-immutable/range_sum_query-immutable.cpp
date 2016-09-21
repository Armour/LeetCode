class NumArray {
public:
    vector<int> sum;
    
    NumArray(vector<int> &nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum.push_back(s += nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sum[j];
        else return sum[j] - sum[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
