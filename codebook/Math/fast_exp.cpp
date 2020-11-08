const ll MOD = 1e9 + 7;

// a^b
ll fast_pow(ll a, ll b) {
    // b %= (MOD - 1) // if MOD is prime, Fermat's little theorem
    ll ans = 1;
    ll base = a % MOD;
    while (b) {
        if (b & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return ans;
}