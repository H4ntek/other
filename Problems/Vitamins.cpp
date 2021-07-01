//Problem "Vitamins" from CF: https://codeforces.com/problemset/problem/1042/B
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int INF = 1e9 + 1;

void solve(){
    int n, cost, mask, ans;
    string s;
    cin >> n;
    int dp[n + 1][8];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < 8; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        cin >> cost >> s;
        mask = 0;
        for (int v = 0; v < 3; v++){
            char c = 'A' + v;
            bool exist = false;
            for (char ch : s){
                exist |= (ch == c);
            }
            if (exist){
                mask += (1 << v);
            }
        }
        for (int m = 0; m < 8; m++){
            dp[i + 1][m] = min(dp[i + 1][m], dp[i][m]);
            dp[i + 1][m | mask] = min(dp[i + 1][m | mask], dp[i][m] + cost);
        }
    }

    ans = dp[n][7];
    cout << (ans == INF ? -1 : ans) << "\n";
}

int main (){
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
