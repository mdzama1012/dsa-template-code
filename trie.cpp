#define N 30

struct TrieNode {
    bool is_end;
    TrieNode *child[N];

    TrieNode() {
        is_end = false;
        memset(child, 0, sizeof child);
    }
};

class Trie {
    TrieNode root;

  public:
    Trie() { TrieNode root = TrieNode(); }

    void insert(const string &word) {
        TrieNode *r = &root;
        for (const char c : word) {
            int i = c - 'a';
            if (r->child[i] == 0)
                r->child[i] = new TrieNode();
            r = r->child[i];
        }
        r->is_end = true;
    }

    bool search(const string &word) {
        TrieNode *r = &root;
        bool is_ended = false;
        for (const char c : word) {
            int i = c - 'a';
            if (r->child[i] == 0)
                return false;
            r = r->child[i];
            is_ended = r->is_end;
        }
        return is_ended;
    }

    bool startsWith(const string &prefix) {
        TrieNode *r = &root;
        for (const char c : prefix) {
            int i = c - 'a';
            if (r->child[i] == 0)
                return false;
            r = r->child[i];
        }
        return true;
    }
};
