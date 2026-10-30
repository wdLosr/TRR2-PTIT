// wdLosr - Le Loc
// CAY KHUNG 1
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;
int t, n, s;
vector<vector<int>> edges(105);
vector<bool> vs(105, false);
vector<pair<int, int>> res;

void dfs(int u)
{
    vs[u] = 1;
    for(auto v : edges[u])
    {
        if(!vs[v])
        {
            int x = u, y = v;
            if(x > y) swap(x, y);
            res.emplace_back(x, y);
            dfs(v);
        }
    }
}

void bfs(int k)
{
    queue<int> q;
    vs[k] = 1;
    q.push(k);

    while(q.size())
    {
        int u = q.front();
        q.pop();

        for(auto v : edges[u])
        {
            if(!vs[v])
            {
                vs[v] = 1;
                q.push(v);
                int x = u, y = v;
                if(x > y) swap(x, y);
                res.emplace_back(x, y);
            }
        }
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    fast;
    cin >> t >> n >> s;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int x; cin >> x;
            if(x) edges[i].emplace_back(j);
        }
    }

    if(t == 1)
    {
        dfs(s);
        for(int i = 1; i <= n; ++i)
        {
            if(!vs[i]) return cout << 0, 0;
        }
        cout << res.size() << endl;
        for(auto [x, y] : res) cout << x << ' ' << y << endl;
    }
    else 
    {
        bfs(s);
        for(int i = 1; i <= n; ++i)
        {
            if(!vs[i]) return cout << 0, 0;
        }
        cout << res.size() << endl;
        for(auto [x, y] : res) cout << x << ' ' << y << endl;
    }
    return 0;
}
