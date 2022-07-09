#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int MAXN = 3e5 + 7;   

char letter[MAXN];
vector <int> adj[MAXN];
int n, ans, indeg[MAXN], dp[MAXN];
vector <int> topo;

void toposort(){
    queue <int> q;
    for (int i = 1; i <= n; i++){
        if (indeg[i] == 0){
            q.push(i);
            topo.push_back(i);
        }
    }

    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto it = adj[v].begin(); it != adj[v].end(); it++){
            indeg[*it]--;
            if (indeg[*it] == 0){
                q.push(*it);
                topo.push_back(*it);
            }
        }
    }
}

void do_dp(char c){
    for (int i = 0; i < n; i++){
        int v = topo[i];
        if (letter[v] == c){
            dp[v]++;
        }
        ans = max(ans, dp[v]);
        for (auto it = adj[v].begin(); it != adj[v].end(); it++){
            dp[*it] = max(dp[*it], dp[v]);
        }
    }
}

void solve(){
    int m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> letter[i];
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    toposort();
    if ((int) topo.size() != n){
        cout << "-1\n";
        return;
    }

    int best = 1;
    for (char c = 'a'; c <= 'z'; c++){
        do_dp(c);
        memset(dp, 0, sizeof(dp));
        best = max(best, ans);
        ans = 0;
    }
    cout << best << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}   
