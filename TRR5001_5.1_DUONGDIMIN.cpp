// wdLosr - Le Loc
// Dijkstra
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n, s, t;
vector<vector<int>> adj(105, vector<int> (105, 0));

int main()
{
    fast;
    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);
    
    cin >> n >> s >> t;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> adj[i][j];
        }
    }

    vector<int> dist(n + 1, INT_MAX); // luu khoang cach ngan nhat tu s den i
    vector<int> parent(n + 1, -1); // luu dinh truoc cua i
    dist[s] = 0; // khoang cach bang 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        for(int v = 1; v <= n; ++v)
        {
            if(adj[u][v] != 0 && adj[u][v] != 10000 && dist[v] > dist[u] + adj[u][v])
            {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    int tmp = t;
    vector<int> path;
    while(tmp != -1)
    {
        path.push_back(tmp);
        tmp = parent[tmp];
    }
    reverse(all(path));
    if(dist[t] == INT_MAX) cout << 0;
    else
    {
        cout << dist[t] << endl;
        for(auto &x : path) cout << x << ' ';
    }
    return 0;
}
