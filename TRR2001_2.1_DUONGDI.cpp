// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int t, n, u ,v;
vector<vector<int>> edges(105), adj(105, vector<int> (105, 0));
vector<bool> vs(105, false);
vector<int> path;

bool findPath(int st, int en)
{
    if(st == en)
    {
        path.emplace_back(en);
        return true;
    }
    vs[st] = 1;
    for(auto x : edges[st])
    {
        if(!vs[x])
        {
            if(findPath(x, en))
            {
                path.emplace_back(st);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    fast;
    //freopen("TK.INP", "r", stdin);
    //freopen("TK.OUT", "w", stdout);
    
    cin >> t >> n >> u >> v;
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
        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            res += adj[u][i] * adj[i][v];
        }
        cout << res;
    }
    else
    {
        if(findPath(u, v))
        {
            reverse(all(path));
            for(auto i : path) cout << i << ' ';
        }
        else cout << "0";
    }
    return 0;
}
