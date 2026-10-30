// wdLosr - Le Loc
// Prim
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

vector<pair<int, int>> adj[105];
vector<bool> vs(105, 0);
vector<Edge> res;

int n, s;

ll prim(int s)
{
    ll mst = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, s});

    while(pq.size())
    {
        auto [w, u, v] = pq.top();
        pq.pop();

        if(vs[v]) continue;
        vs[v] = 1;
        mst += w;

        if(u)
        {
            int x = u, y = v;
            if(x > y) swap(x, y);
            res.push_back({x, y, w});
        }

        for(auto [to, wei] : adj[v])
        {
            if(!vs[to])
            {
                pq.push({wei, v, to});
            }
        }
    }
    return mst;
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    fast;
    cin >> n >> s;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int w; cin >> w;
            if(w) adj[i].emplace_back(j, w);
        }
    }

    ll mst = prim(s);
    if(res.size() != n - 1) return cout << 0, 0;
    cout << mst << endl;
    for(auto [x, y, w] : res) cout << x << ' ' << y << ' ' << w <<endl;
    return 0;
}
