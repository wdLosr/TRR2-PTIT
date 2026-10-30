// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()

using namespace std;
int n, st, cnt;
vector<vector<int>> edges(105);
vector<int> res;
vector<bool> vs(105, false);

void hamilton(int cur, int k)
{
    if(k == n)
    {
        for(auto v : edges[cur])
        {
            if(st == v)
            {
                ++cnt;
                for(auto x : res) cout << x << ' ';
                cout << st << endl;
                break;
            }
        }
        return;
    }

    for(auto v : edges[cur])
    {
        if(!vs[v])
        {
            vs[v] = 1;
            res.emplace_back(v);
            hamilton(v, k + 1);
            vs[v] = 0;
            res.pop_back();
        }
    }
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    fast;
    cin >> n >> st;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int x; cin >> x;
            if(x) edges[i].emplace_back(j);
        }
    }
    vs[st] = 1;
    res.emplace_back(st);
    hamilton(st, 1);
    cout << cnt;
    return 0;
}
