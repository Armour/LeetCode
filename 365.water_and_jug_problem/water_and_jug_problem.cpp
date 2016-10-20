class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y) >= z && z % gcd(x, y) == 0;
    }
    
    int gcd(int a, int b) {
        return (b == 0)? a: gcd(b, a % b);
    }
};
