// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n, timer;
vector<vector<int>> edges(105);
vector<int> tin(105), low(105), parent(105, -1);
vector<pair<int, int>> cau;
vector<bool> vs(105, false);

void dfs(int u)
{
    vs[u] = true;
    tin[u] = low[u] = ++timer;
    for(auto v : edges[u])
    {
        if(!vs[v])
        {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) cau.emplace_back(min(u, v), max(u, v));
        }
        else if(v != parent[u])
        {
            low[u] = min(low[u], tin[v]);
        }
    }
}
int main()
{
    fast;
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int x; cin >> x;
            if(x)
            {
                edges[i].emplace_back(j);
                edges[j].emplace_back(i);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!vs[i]) dfs(i);
    }

    cout << cau.size() << endl;
    sort(all(cau));
    for(auto &x : cau) cout << x.first << ' ' << x.second << endl;
    return 0;
}
