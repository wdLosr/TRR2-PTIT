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
vector<int> tin(105), low(105), res, parent(105, -1);
vector<bool> vs(105, false), cut(105, false);

void dfs(int u)
{
    vs[u] = true;
    tin[u] = low[u] = ++timer;
    int child = 0;
    for(auto v : edges[u])
    {
        if(!vs[v])
        {
            ++child;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] && parent[u] != -1) cut[u] = true;
            if(parent[u] == -1 && child > 1) cut[u] = true;
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
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

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

    timer = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!vs[i]) dfs(i);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(cut[i]) res.emplace_back(i);
    }

    cout << res.size() << endl;
    sort(all(res));
    for(auto x : res) cout << x << ' ';
    return 0;
}
