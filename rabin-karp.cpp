constexpr int p = 31;
constexpr int m = 1e9 + 9;

class Solution {
private:
    int rabinKarp(string& text, string& pattern) {
        int T = text.length();
        int P = pattern.length();

        // Edge case
        if (T == 0 || P == 0 || T < P) return -1;

        // Find hash of pattern
        int power = 1;
        int patternHash = 0;
        for (int i = 0; i < P; i++) {
            int x = pattern[i] - 'a' + 1;
            patternHash = (patternHash + ((long long)(x) * power)) % m;
            power = (power * (long long)(p)) % m;
        }

        // Make prefix array of hashes i.e. prefix[i] := hash of [0, i]
        power = 1;
        vector<int> hashPrefix(T + 1, 0);
        for (int i = 0; i < T; i++) {
            int x = text[i] - 'a' + 1;
            hashPrefix[i + 1] = (hashPrefix[i] + ((long long)(x) * power)) % m;
            power = (power * (long long)(p)) % m;
        }

        // For each window in text of size pattern, check for equal hashes
        power = 1;
        for (int i = 0; i < T - P + 1; i++) {
            int currHash = (hashPrefix[i + P] - hashPrefix[i] + m) % m;
            if (currHash == ((long long)(patternHash) * power) % m) {
                // Can handle collision handling, if test case arn't passing.
                return i;
            }
            power = (power * (long long)(p)) % m;
        }
        return -1;
    }

public:
    int strStr(string &haystack, string &needle) {
        return rabinKarp(haystack, needle);
    }
};
