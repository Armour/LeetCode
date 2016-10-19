class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        if (n == 0) return res;
        for (int i = 1; i <= n; i++) {
            bool mod3 = (i % 3 == 0);
            bool mod5 = (i % 5 == 0);
            if (mod3 && mod5)
                res.push_back("FizzBuzz");
            else if (mod3)
                res.push_back("Fizz");
            else if (mod5)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};
