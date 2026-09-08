class Solution {
public:
    int countCommas(long n) {
        long total = 0;
        long low = 1;
        int digits = 1;
        while (low <= n) {
            long high = low * 10 - 1;      // largest number with `digits` digits
            long hi = min(high, n);
            long count = hi - low + 1;     // how many numbers with this digit length
            total += count * ((digits - 1) / 3);
            low *= 10;
            digits++;
        }
        return total;
    }
};