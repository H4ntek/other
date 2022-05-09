#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int MAXN = 5003;

int dp[MAXN][MAXN]; //dp[i][j] - długość LCS po rozważeniu s1 do i, s2 do j
char memo[MAXN][MAXN];

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            memo[i][j] = '$';
        }
    }

    if (s1[0] == s2[0]){
        dp[0][0] = 1;
        memo[0][0] = s1[0];
    }
    for (int i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][0], (s1[i] == s2[0] ? 1 : 0)); 
        if (s1[i] == s2[0]){
            memo[i][0] = s1[i];
        }
    }
    for (int j = 1; j < m; j++){
        dp[0][j] = max(dp[0][j - 1], (s1[0] == s2[j] ? 1 : 0)); 
        if (s1[0] == s2[j]){
            memo[0][j] = s2[j];
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (s1[i] == s2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                memo[i][j] = s1[i];
            }
            else if (dp[i - 1][j] > dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j];
                memo[i][j] = memo[i - 1][j];
            }
            else{
                dp[i][j] = dp[i][j - 1];
                memo[i][j] = memo[i][j - 1];
            }
        }
    }

    string lcs;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0){
        if (s1[i] == s2[j]){
            lcs += memo[i][j];
            i--;
            j--;
            continue;
        }
        if (dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << dp[n - 1][m - 1] << "\n" << lcs << "\n";
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
