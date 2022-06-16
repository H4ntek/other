// CF 161D
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int MAXN = 5e4 + 3, MAXK = 503;

int k, dp[MAXN][MAXK]; // dp[v][i] - ile jest synow v, ktorzy sa oddaleni o i
vector <int> adj[MAXN];
lli ans = 0;

void DFS(int v, int par){
    dp[v][0] = 1;
    for (int child : adj[v]){
        if (child != par){
            DFS(child, v);
            for (int i = 0; i < k; i++){
                ans += 1LL * dp[v][i] * dp[child][k - i - 1];
                if (i != 0){
                    dp[v][i] += dp[child][i - 1];
                }
            }
        }
    }
}

void solve(){
    int n, a, b;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1, -1);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}   
