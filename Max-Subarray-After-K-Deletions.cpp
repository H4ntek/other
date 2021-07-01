#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int INF = 1e9;

void solve(){
	int n, k, mx = -INF;
	cout << "n: ";
	cin >> n;
	cout << "k: ";
	cin >> k;
	vector <int> a(n);
	cout << "Array: ";
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int dp[n][k + 1];
	//dp[i][j] = max subarray sum out of subarrays ending up to i having removed up to k - j elements
	int best = -INF;
	memset(dp, -1, sizeof(dp));
	for (int j = 0; j <= k; j++){
		dp[0][j] = max(0, a[0]);
		best = max(best, dp[0][j]);
	}
	for (int i = 1; i < n; i++){
		for (int j = k; j >= 0; j--){
			int include = max(0, a[i] + dp[i - 1][j]);
			if (j == 0){
				dp[i][0] = include;
			}
			else{
				int remove = dp[i - 1][j - 1];
				dp[i][j] = max(remove, include);
			}
			best = max(dp[i][j], best);
		}
	}
	if (mx < 0){
		best = mx;
	}
	cout << "Max subarray sum with at most k deletions: " << best << "\n";
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int t;
	cout << "Number of cases: ";
    cin >> t;
    //t = 1;
    while (t--){
        solve();
    }
    return 0;
}
