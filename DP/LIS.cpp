#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

#define ff first
#define ss second

const int BASE = (1 << 18);

int st[2 * BASE];

int query(int qs, int qe){
	if (qs > qe){
		return 0;
	}
	int si_s = BASE + qs, si_e = BASE + qe;
	int res = max(st[si_s], st[si_e]);
	while (si_s / 2 != si_e / 2){
		if (si_s % 2 == 0){
			res = max(res, st[si_s + 1]);
		}
		si_s /= 2;
		if (si_e % 2 == 1){
			res = max(res, st[si_e - 1]);
		}
		si_e /= 2;
	}
	return res;
}

void update(int ui, int val){
	int si = BASE + ui;
	st[si] = max(st[si], val);
	while (si > 1){
		si /= 2;
		st[si] = max(st[2 * si], st[2 * si + 1]);
	}
}


void solve(){
	int n;
	cin >> n;
	vector <pair <int, int>> temp_a(n);
	for (int i = 0; i < n; i++){
		cin >> temp_a[i].ff;
		temp_a[i].ss = i;
	}
	sort(temp_a.begin(), temp_a.end());
	int val = 1;
	vector <int> a(n);
	a[temp_a[0].ss] = val;
	for (int i = 1; i < n; i++){
		if (temp_a[i].ff > temp_a[i - 1].ff){
			val++;
		}
		a[temp_a[i].ss] = val;
	}
	
	vector <int> dp(n);
	dp[0] = 1;
	update(a[0], 1);
	int ans = 1, best_so_far;
	for (int i = 1; i < n; i++){
		best_so_far = query(1, a[i] - 1);
		dp[i] = max(1, best_so_far + 1);
		update(a[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
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
