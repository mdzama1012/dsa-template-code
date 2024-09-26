#include <bits/stdc++.h>
using namespace std;

#ifdef LocalRun
#include "debugger.hpp"
#else
#define debug(x)
#endif

typedef long long ll;
typedef long double ld;
/********************************************************************/
vector<int> sub_size;
int dfs(int root, vector<int> *edges, int parent) {
    if (sub_size[root] == 0) {
        ++sub_size[root];
        for (const int & edge : edges[root]) {
            if (edge != parent)
                sub_size[root] += dfs(edge, edges, root);
        }
    }
    return sub_size[root];
}
void solve() {
    int n;
    cin >> n;
    vector<int> *edges = new vector<int>[n];
    for (int i = 0; i < n - 1; i++) {
        // creating a general tree, so we can root it on whatever node we want.
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }
    // In order to find size of sub-tree a tree must be rooted.
    sub_size = vector<int>(n, 0);
    dfs(0, edges, -1);

    // display size of all the sub-trees.
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ':' << sub_size[i] << '\n';
    }
    delete [] edges;
}
/********************************************************************/
int main() {
#ifdef LocalRun
    freopen("D:/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
