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

	// gracz 1 zbiera dodatnie punkty, a 2 ujemne
	
    for (int i = 1; i <= n; i++){
		dp[i][0] += a[i];
		dp[i][1] += -a[i];
		for (int j = 2 * i; j <= n; j += i){
			dp[j][0] = min(dp[i][1], dp[j][0]); // g2 minimlaizuje w1 - w2, więc po tym jak g1 zrobi ruch, g2 wybierze minimum z poprzednich dp
			dp[j][1] = max(dp[i][0], dp[j][1]); // g1 maksymalizuje w1 - w2, więc po tym jak g2 zrobi ruch, g1 wybierze maksa z poprzednich dp
		}
	}

    lli ans = dp[1][0];
    for (int i = 2; i <= n; i++){
		ans = max(dp[i][0], ans); // zaczyna g1, więc do odpowiedzi bierzemy pod uwagę tylko jego starty
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
