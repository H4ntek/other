#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void solve(){
	int n, k;
	cout << "n: ";
	cin >> n;
	cout << "k: ";
	cin >> k;
	vector <int> a(n), dp(k + 1, 0);
	dp[0] = 1;
	//dp[i] = last element in a sum that equals i
	cout << "Set: ";
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	if (k == 0){
	    cout << "Empty subset\n";
	    return;
	}
	for (int i = 0; i < n; i++){
		int x = a[i];
		for (int suma = k; suma >= x; suma--){
			if (dp[suma - x] != 0 && dp[suma] == 0){
				dp[suma] = x;
			}
		}
	}
	if (dp[k] == 0){
		cout << "Sum can't be made\n";
		return;
	}
	cout << "Subset: ";
	while (k > 0){
		cout << dp[k] << " ";
		k -= dp[k];
	}
	cout << "\n";
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
