// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n;
vector<vector<int>> adj(105);

int bfs(int del)
{
    vector<bool> vs(n + 1, false);
    vs[del] = true;
    int cnt = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        if(!vs[i])
        {
            ++cnt;
            queue<int> q;
            q.push(i);
            vs[i] = true;
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();

                for(auto x : adj[cur])
                {
                    if(!vs[x])
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
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }

    vector<int> res;
    int cnt = bfs(0);
    for(int i = 1; i <= n; ++i)
    {
        if(bfs(i) > cnt) res.emplace_back(i);
    }

    cout << res.size() << endl;
    if(res.size())
    {
        sort(all(res));
        for(auto x : res) cout << x << ' ';
    }
    return 0;
}
