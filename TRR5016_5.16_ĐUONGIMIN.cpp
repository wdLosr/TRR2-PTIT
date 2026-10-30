// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;
int n;
const int INF = 1e9;

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    fast;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<vector<int>> parent(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int x; cin >> x;
            if(i == j)
            {
                adj[i][j] = 0;
                parent[i][j] = j;
            }
            else if(x != 0 && x != 10000)
            {
                adj[i][j] = x;
                parent[i][j] = j;
            }
            else
            {
                adj[i][j] = INF;
                parent[i][j] = -1;
            }
        }
    }

    for(int k = 1; k <= n; ++k)
    {
        for(int u = 1; u <= n; ++u)
        {
            if(adj[u][k] == INF) continue;
            for(int v = 1; v <= n; ++v)
            {
                if(adj[k][v] == INF) continue;
                int via = adj[u][k] + adj[k][v];
                if(via < adj[u][v])
                {
                    adj[u][v] = via;
                    parent[u][v] = parent[u][k];
                }
            }
        }
    }

    int mx = -1;
    int U = 0, V = 0;
    for(int u = 1; u <= n; ++u)
    {
        for(int v = 1; v <= n; ++v)
        {
            if(u == v) continue;
            if(adj[u][v] < INF)
            {
                if(adj[u][v] > mx || (adj[u][v] == mx && (u < U || (u == U && v < V))))
                {
                    mx = adj[u][v];
                    U = u; V = v;
                }
            }
        }
    }

    if(mx < 0) return cout << 0, 0;
    cout << U << ' ' << V << ' ' << mx << endl;
    vector<int> ans;
    int cur = U;
    ans.push_back(cur);
    while(cur != V)
    {
        cur = parent[cur][V];
        ans.push_back(cur);
    }

    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
