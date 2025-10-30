class Solution {
public:
    long long powMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
    int countGoodNumbers(long long n) {
        const long long mod = 1e9 + 7;
        if(n == 1) return 5;
        long long even_count = (n + 1)/2 ;
        long long odd_count = (n/2);
        long long total = (powMod(5, even_count, mod) * powMod(4, odd_count, mod)) % mod;
        return int(total);
    }
};