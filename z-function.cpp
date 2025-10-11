vector<int> zArray(string const& s) {
    int n = s.length();

    vector<int> z(n, 0);

    z[0] = 0;
    int l = 0;
    int r = 0;
    for(int i = 1; i < n; i++) {
        if (i >= l && i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        int H = haystack.length();
        int N = needle.length();

        string s = needle + "$" + haystack;
        vector<int> z = zArray(s);

        for(int i = 0; i < z.size(); i++) {
            if (z[i] == N) {
                return i - N - 1;
            }
        }
        return -1;
    }
};
