// wdLosr - Le Loc
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int t, n;
vector<vector<int>> adj(105);
vector<vector<bool>> used(105, vector<bool> (105, false));

int main()
{
    fast;
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    cin >> t >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int x; cin >> x;
            if(x) adj[i].push_back(j);
        }
    }

    if(t == 1)
    {
        for(int i = 1; i <= n; ++i)
        {
            cout << adj[i].size() << ' ';
        }
    }
    else
    {
        cout << n << endl;
        for(int i = 1; i <= n; ++i)
        {
            cout << adj[i].size() << ' ';
            
            for(auto x : adj[i]) cout << x << ' ';
            
            cout << endl;
        }
    }

    return 0;
}
