#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;
    string p;
    cin >> t;
    cin >> p;
    string s = p + '#' + t;

    int T = t.length();
    int P = p.length();
    int S = T + P + 1;

    // build LPS array (longest proper prefix which is also a suffix) also known as pi array
    vector<int> pi(S, 0);

    for(int i = 1; i < S; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            pi[i] = j+1;
        }
    }

    for(int i = 0; i < S; i++) {
        if (pi[i] == P) {
            cout << i - 2 * P << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
