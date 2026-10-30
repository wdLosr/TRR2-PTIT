// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;
int n, t, k;
vector<vector<int>> adj(105, vector<int> (105, 0)), edges(105);
vector<bool> vs(105, false);

void dfs(int u)
{
    vs[u] = true;
    for(auto v : edges[u])
    {
        if(!vs[v]) dfs(v);
    }
}

vector<int> findPath(int k)
{
    stack<int> st;
    vector<int> res;
    st.push(k);
    
    while(!st.empty())
    {
        bool found = false;

        int u = st.top();
        for(int v = 1; v <= n; ++v)
        {
            if(adj[u][v])
            {
                found = true;
                adj[u][v] = adj[v][u] = 0;
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
            if(adj[i][j]) edges[i].emplace_back(j);
        }
    }

    if(t == 1)
    {
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(!vs[i] && edges[i].size())
            {
                ++cnt;
                dfs(i);
            }
        }

        if(cnt > 1) return cout << 0, 0;
        int odd = 0;
        for(int i = 1; i <= n; ++i)
        {
            odd += (edges[i].size() & 1);
        }

        if(odd == 0) cout << 1;
        else if(odd == 2) cout << 2;
        else cout << 0;
    }
    else
    {
        vector<int> path = findPath(k);
        reverse(all(path));
        for(auto x : path) cout << x << ' ';
    }
    return 0;
}
