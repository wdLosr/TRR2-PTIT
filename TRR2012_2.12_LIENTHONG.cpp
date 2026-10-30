// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n;
vector<vector<int>> edges(105);
vector<bool> vs(105, false);

void bfs(int u, vector<int> &res)
{
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    res.emplace_back(u);

    while(q.size())
    {
        int cur = q.front();
        q.pop();

        for(auto x : edges[cur])
        {
            if(!vs[x])
            {
                vs[x] = 1;
                res.emplace_back(x);
                q.push(x);
            }
        }
    }
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
            bfs(i, res);
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
