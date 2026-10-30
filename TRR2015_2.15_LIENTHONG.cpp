// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n;
vector<bool> vs(105, false);
vector<vector<int>> edges(105), rev_edges(105);

int dfs_cnt(int u, vector<vector<int>> &adj)
{
    vs[u] = true;
    int cnt = 1;
    for(auto v : adj[u])
    {
        if(!vs[v]) cnt += dfs_cnt(v, adj);
    }
    return cnt;
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
                rev_edges[j].emplace_back(i);
            }
        }
    }

    int cnt1 = dfs_cnt(1, edges);
    vs.assign(105, false);
    int cnt2 = dfs_cnt(1, rev_edges);

    if(cnt1 == n && cnt2 == n) cout << "1";
    else if(cnt1 == n || cnt2 == n) cout << "2";
    else cout << "0";
    return 0;
}
