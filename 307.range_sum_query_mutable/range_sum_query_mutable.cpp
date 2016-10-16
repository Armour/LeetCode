class NumArray {
public:
    vector<int> sum;
    vector<int> nums;

    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        for (int i = 0; i < nums.size(); i++) {
            sum.push_back(0);
            this->nums.push_back(0);
        }
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int n = sum.size();
        int dist = val - nums[i];
        nums[i] = val;
        i++;
        while (i <= n) {
            sum[i - 1] += dist;
            i += i & -i;
        }
    }
    
    int get_sum(int i) {
        int res = 0;
        i++;
        while (i > 0) {
            res += sum[i - 1];
            i -= i & -i;
        }
        return res;
    }

    int sumRange(int i, int j) {
        int sumj = get_sum(j);
        int sumi = get_sum(i - 1);
        return sumj - sumi;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
