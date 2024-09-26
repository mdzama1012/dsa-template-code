int gcd(int a, int b) {
    int t;
    while (b > 0) {
        t = a;
        a = b;
        b = t % a;
    }
    return (a);
}
