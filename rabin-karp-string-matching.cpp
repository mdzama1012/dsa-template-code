// return: index of match.
vector<int> rabin_karp(const string &s, const string &t) {
    const int n = s.length();
    const int m = t.length();

    if (n == 0 or m == 0 or n < m) {
        return vector<int>(0);
    }
    const int p = 17;
    const int mod = 1e9 + 7;

    int hash_t = 0;
    for (int i = 0, pow = 1; i < m; i++) {
        hash_t = (hash_t + ((t[i] - 'a' + 1) * (ll)pow) % mod) % mod;
        pow = ((ll)pow * p) % mod;
    }

    // Rabin Karp algorithm...
    vector<int> found_at;
    vector<int> dp = vector<int>(n);

    dp[0] = (s[0] - 'a' + 1);
    for (int i = 1, pow = p; i < n; i++) {
        dp[i] = (dp[i - 1] + ((s[i] - 'a' + 1) * (ll)pow) % mod) % mod;
        pow = ((ll)pow * p) % mod;
    }

    int l = 0, r = m - 1, pow = 1;
    while (r < n) {
        int hash_win = dp[r];
        if (l != 0)
            hash_win = (dp[r] - dp[l - 1] + mod) % mod;

        // handle collision...
        if (hash_win == ((ll)pow * hash_t) % mod) {
            bool unequal = false;
            for (int i = l, j = 0; i <= r; i++, j++) {
                if (s[i] != t[j]) {
                    unequal = true;
                    break;
                }
            }
            if (not unequal)
                found_at.push_back(l + 1);
        }
        pow = ((ll)pow * p) % mod;
        r++, l++;
    }
    return found_at;
}
