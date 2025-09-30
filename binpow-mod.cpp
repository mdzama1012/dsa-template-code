ll binpow_mod_recursive(ll a, ll b, ll m) {
    if (b > 0) {
        ll ans = binpow_mod_recursive(a, b / 2, m);
        if (b % 2 == 1) {
            return (ans * ans % m * (a % m)) % m;
        } else {
            return (ans * ans) % m;
        }
    }
    return (1);
}

ll binpow_mod_iterative(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b) {
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
