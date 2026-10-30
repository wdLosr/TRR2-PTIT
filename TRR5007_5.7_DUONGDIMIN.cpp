// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;
int n, s, t;
const int INF = 1e9;
struct E
{
    int u, v, w;
};
vector<E> adj;

int main()
{
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    fast;

    cin >> n >> s >> t;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int x; cin >> x;
            if(x != 0 && x != 10000) adj.push_back({i, j, x});
        }
    }

    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[s] = 0;
    
    for(int i = 1; i < n; ++i)
    {
        for(auto &e : adj)
        {
            auto [u, v, w] = e;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    for(auto &e : adj)
    {
        auto [u, v, w] = e;
        if(dist[v] > dist[u] + w)
        {
            return cout << -1, 0;
        }
    }
    if(dist[t] == INF) return cout << 0, 0;
    vector<int> path;
    int tmp = t;
    while(tmp != -1)
    {
        path.push_back(tmp);
        tmp = parent[tmp];
    }

    reverse(all(path));
    cout << dist[t] << endl;
    for(auto &x : path) cout << x << ' ';
    return 0;
}
