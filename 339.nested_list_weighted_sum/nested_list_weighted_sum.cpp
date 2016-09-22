/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int getSum(vector<NestedInteger>& nestedList, int depth) {
        if (nestedList.size() == 0) return 0;
        int sum = 0;
        for (auto n: nestedList) {
            if (n.isInteger()) {
                sum += n.getInteger() * depth;
            } else {
                sum += getSum(n.getList(), depth + 1);
            }
        }
        return sum;
    }

    int depthSum(vector<NestedInteger>& nestedList) {
        return getSum(nestedList, 1);
    }
};
