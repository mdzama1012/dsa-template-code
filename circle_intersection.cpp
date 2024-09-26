int isIntersecting(ll r1, ll x1, ll y1, ll r2, ll x2, ll y2) {
    // distance between c1 and c2.
    ld d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (d <= abs(r2 - r1))
        return (d == 0 ? 4 : 3); // Overlapping or Concentric.
    else if (d == r1 + r2)
        return 1; // Touching.
    else if (d < r1 + r2)
        return 2; // Intersecting.
    else
        return 0; // Not overlapping
}
