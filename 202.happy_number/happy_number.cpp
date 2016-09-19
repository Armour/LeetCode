class Solution {
public:
    int happy(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        set<int> res;
        while (n != 1) {
            int tmp = happy(n);
            if (res.find(tmp) != res.end()) break;
            res.insert(tmp);
            n = tmp;
        }
        return n == 1;
    }
};
