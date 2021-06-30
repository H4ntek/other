#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int INF = 1e9;

//Kadane's algo
void solve(){
	int n;
	cout << "n: ";
	cin >> n;
	cout << "Array: ";
	vector <int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	lli best = -INF, curr = 0;
	for (int i = 0; i < n; i++){
		curr += a[i];
		best = max(best, curr);
		curr = max(0LL, curr);
	}
	cout << "Max subarray sum: " << best << "\n";
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
