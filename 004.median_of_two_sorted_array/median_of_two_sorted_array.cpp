class Solution {
public:
    int findKthNumber(vector<int> &nums1, vector<int> &nums2, int k, int idx1, int idx2) {
        if (idx1 >= nums1.size()) return nums2[idx2 + k - 1];
        if (idx2 >= nums2.size()) return nums1[idx1 + k - 1];
        if (k == 1) {
            return min(nums1[idx1], nums2[idx2]);
        }
        if (idx1 + k / 2 > nums1.size()) {
            return findKthNumber(nums1, nums2, k - k / 2, idx1, idx2 + k / 2);
        } else if (idx2 + k / 2 > nums2.size()) {
            return findKthNumber(nums1, nums2, k - k / 2, idx1 + k / 2, idx2);
        } else if (nums1[idx1 + k / 2 - 1] < nums2[idx2 + k / 2 - 1]) {
            return findKthNumber(nums1, nums2, k - k / 2, idx1 + k / 2, idx2);
        } else {
            return findKthNumber(nums1, nums2, k - k / 2, idx1, idx2 + k / 2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size() + nums2.size();
        if (k == 0) return 0;
        if (k == 1) {
            return nums1.size()? nums1[0]: nums2[0];
        }
        if (k % 2 == 0) {
            return (findKthNumber(nums1, nums2, k / 2, 0, 0) + findKthNumber(nums1, nums2, (k / 2) + 1, 0, 0)) / 2.0;
        } else {
            return findKthNumber(nums1, nums2, k / 2 + 1, 0, 0);
        }
    }
};
