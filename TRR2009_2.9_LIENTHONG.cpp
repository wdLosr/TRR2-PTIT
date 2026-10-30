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
vector<vector<int>> edges(105);

void dfs(int u, vector<int> &res)
{
    vs[u] = true;
    res.emplace_back(u);
    for(auto v : edges[u])
    {
        if(!vs[v]) dfs(v, res);
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

    int cnt = 0;
    vector<vector<int>> ans;
    for(int i = 1; i <= n; ++i)
    {
        if(!vs[i])
        {
            vector<int> res;
            dfs(i, res);
            ans.emplace_back(res);
            ++cnt;
        }
    }

    cout << cnt << endl;
    for(auto res : ans)
    {
        sort(all(res));
        for(auto x : res) cout << x << ' ';
        cout << endl;
    }
    return 0;
}
