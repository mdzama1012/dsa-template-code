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
vector<pair<int, int> > in_out_time;
int dfs(int root, vector<int> *edges, int parent, int intime) {
    in_out_time[root].first = intime;
    int outtime = intime;
    for (const int & edge : edges[root]) {
        if (edge != parent)
            outtime = dfs(edge, edges, root, outtime + 1);
    }
    return in_out_time[root].second = outtime + 1;
}
void solve() {
    /*
        Given a rooted tree with N vertices and N-1 edges. We will be given many pairs of vertices u and v, we need to tell whether u is an ancestor of v or not. Given tree will be rooted at the vertex with index 0.
    */
    int n, u, v, q;
    cin >> n;
    vector<int> *edges = new vector<int>[n];    // array of vector (edge list).
    for (int i = 0; i < n - 1; i++) {
        // creating a general-tree (unrooted), so we can root it on whatever node we want.
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }
    in_out_time = vector<pair<int, int> >(n, make_pair(0, 0));
    dfs(0, edges, -1, 1);
    // debug(in_out_time);

    cin >> q;   // input number of query.
    while (q -- > 0) {
        cin >> u >> v;
        // print YES if u is an ancestor of v otherwise print NO.
        u--, v--;
        if (in_out_time[u].first < in_out_time[v].first
                and in_out_time[u].second > in_out_time[v].second)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
