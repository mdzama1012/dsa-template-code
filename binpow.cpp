// Iterative Function.
ll binpow_iterative(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2)
            res = res * a;
        a = a * a;
        b = b / 2;
    }
    return res;
}

// Recursive Function.
ll binpow_recursive(ll a, ll b) {
    if (b > 0) {
        ll ans = binpow_recursive(a, b / 2);
        if (b % 2 == 1)
            return ans * ans * a;
        else
            return ans * ans;
    }
    return 1;
}
