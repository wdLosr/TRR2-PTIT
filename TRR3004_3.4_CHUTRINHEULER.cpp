// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;
int t, n, k;
vector<vector<int>> adj(105, vector<int> (105)), edges(105);
vector<bool> vs(105, false);
vector<pair<int, int>> deg(105, {0, 0});

void dfs(int u)
{
    vs[u] = 1;
    for(auto v : edges[u])
    {
        if(!vs[v]) dfs(v);
    }
}

vector<int> euler(int k)
{
    stack<int> st;
    vector<int> res;
    st.push(k);

    while(st.size())
    {
        bool found = false;

        int u = st.top();
        for(int v = 1; v <= n; ++v)
        {
            if(adj[u][v])
            {
                found = true;
                adj[u][v] = 0;
                st.push(v);
                break;
            }
        }

        if(!found)
        {
            res.emplace_back(u);
            st.pop();
        }
    }
    reverse(all(res));
    return res;
}
int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    fast;
    cin >> t >> n;
    if(t == 2) cin >> k;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> adj[i][j];
            if(adj[i][j])
            {
                deg[j].first++;
                deg[i].second++;
                edges[i].emplace_back(j);
            }
        }
    }

    if(t == 1)
    {
        int u = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(deg[i].first || deg[i].second)
            {
                u = i;
                break;
            }
        }
        if(u) dfs(u);

        for(int i = 1; i <= n; ++i)
        {
            if((deg[i].first || deg[i].second) && !vs[i]) return cout << 0, 0;
        }

        int st = 0, en = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(deg[i].first - deg[i].second == 1) en++;
            else if(deg[i].second - deg[i].first == 1) st++;
            else if(deg[i].first != deg[i].second) return cout << 0, 0;
        }

        if(!en || !st) cout << 1;
        else if(en == 1 && st == 1) cout << 2;
        else cout << 0;
    }
    else
    {
        vector<int> path = euler(k);
        for(auto x : path) cout << x << ' ';
    }
    return 0;
}
