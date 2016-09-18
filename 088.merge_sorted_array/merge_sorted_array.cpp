class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int v1 = m - 1;
        int v2 = n - 1;
        for (int i = n + m - 1; i >= 0; i--) {
            if (v1 < 0) {
                nums1[i] = nums2[v2--];
            } else if (v2 < 0) {
                nums1[i] = nums1[v1--];
            } else {
                if (nums1[v1] > nums2[v2]) {
                    nums1[i] = nums1[v1--];
                } else {
                    nums1[i] = nums2[v2--];
                }
            }
        }
    }
};
