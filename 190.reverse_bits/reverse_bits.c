uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    int i = 0;
    while (i < 32) {
        ans *= 2;
        ans += n % 2;
        n /= 2;
        i++;
    }
    return ans;
}
