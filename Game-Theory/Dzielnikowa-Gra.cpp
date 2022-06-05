// zadanie z turnieju solve 4.06.2022 - DZI0
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const lli INF = 1e18 + 3;

void solve(){
    int n;
    cin >> n;
    vector <lli> a(n + 1);
	lli dp[n + 1][2];
	for (int i = 1; i <= n; i++){
	    cin >> a[i];
	}

	dp[1][0] = dp[1][1] = 0;
	for (int i = 2; i <= n; i++){
		dp[i][0] = INF;
		dp[i][1] = -INF;
	}

    for (int i = 1; i <= n; i++){
		dp[i][0] += a[i];
		dp[i][1] += -a[i];
		for (int j = 2 * i; j <= n; j += i){
			dp[j][0] = min(dp[i][1], dp[j][0]);
			dp[j][1] = max(dp[i][0], dp[j][1]);
		}
	}

    lli ans = dp[1][0];
    for (int i = 2; i <= n; i++){
		ans = max(dp[i][0], ans);
	}
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    //cin >> t;
    t = 1;
    while (t--){
        solve();
    }
    return 0;
}
