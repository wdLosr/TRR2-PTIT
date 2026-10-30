// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n;
vector<vector<int>> adj(105, vector<int> (105, 0));

int bfs()
{
    vector<bool> vs(n + 1, false);
    int cnt = 0;
    queue<int> q;

    for(int i = 1; i <= n; ++i)
    {
        if(!vs[i])
        {
            ++cnt;
            q.push(i);
            vs[i] = true;
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();

                for(int x = 1; x <= n; ++x)
                {
                    if(adj[cur][x] && !vs[x])
                    {
                        vs[x] = true;
                        q.push(x);
                    }
                }
            }
        }
    }
    return cnt;
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
            cin >> adj[i][j];
        }
    }

    int cnt = bfs();
    vector<pair<int, int>> res;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            if(adj[i][j])
            {
                adj[i][j] = adj[j][i] = 0;
                if(bfs() > cnt) res.emplace_back(i, j);
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }

    cout << res.size() << endl;
    if(res.size())
    {
        sort(all(res));
        for(auto &x : res) cout << x.first << ' ' << x.second << endl;
    }
    
    return 0;
}
