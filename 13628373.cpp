#include <bits/stdc++.h>
#define lim 200001
using namespace std;
int n,dp[lim],u,v;
vector<int> adj[lim];
int cal(int u)
{
    if(dp[u] != -1) return dp[u];
    int sum = 0;
    for(int v:adj[u]) sum += cal(v);
    return dp[u] = sum + adj[u].size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int u = 2; u <= n; ++u)
    {
        cin >> v;
        adj[v].push_back(u);
    }
    memset(dp, -1, sizeof dp);
    cal(1);
    for(int u = 1; u <= n; ++u) cout << dp[u] << ' ';
    return 0;
}
