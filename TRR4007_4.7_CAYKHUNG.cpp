// wdLosr - Le Loc
// Kruskal
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;
struct Edge
{
    int u, v, w;
};

int n, m;
vector<int> parent(105, 0), sz(105, 1);
vector<Edge> res, a;

bool cmp(Edge x, Edge y)
{
    if(x.w != y.w) return x.w < y.w;
    else if(x.u < y.u) return x.u < y.u;
    else return x.v < y.v;
}

int findSet(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = findSet(parent[u]);
}

int unionSet(int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return 1;
}

ll kruskal()
{
    ll mst = 0;
    for(auto [x, y, w] : a)
    {
        if(unionSet(x, y))
        {
            mst += w;
            int u = x, v = y;
            res.push_back({x, y, w});
        }
    }
    return mst;
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    fast;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a.push_back({u, v, w});
    }
    sort(all(a), cmp);
    for(int i = 1; i <= n; ++i) parent[i] = i;
    ll ans = kruskal();
    if(res.size() != n - 1) return cout << 0, 0;
    cout << ans << endl;
    for(auto [x, y, w] : res) cout << x << ' ' << y << ' ' << w << endl; 
    return 0;
}
