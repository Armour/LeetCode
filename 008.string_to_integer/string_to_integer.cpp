class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int sign = 1;
        int i = -1;

        // Handle leading whitespace
        while (str[++i] == ' ');

        // Handle optional leading sign
        if (str[i] == '+') i++;
        else if (str[i] == '-') {
            sign = -1;
            i++;
        }

        for (; i < str.length(); i++) {
            if (str[i] < '0' || str[i] > '9') break;

            // Handle obvious overflows
            if (INT_MAX / 10 < ans) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }

            // Handle last-digit-caused overflows
            if (INT_MAX / 10 == ans) {
                if (sign == 1 && str[i] > '7') return INT_MAX;
                else if (str[i] > '8') return INT_MIN;
            }

            // Append the digit to the number
            ans *= 10;
            ans += str[i] - '0';
        }
        return ans * sign;
    };
};
