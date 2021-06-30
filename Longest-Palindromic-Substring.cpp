#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 1003;

bool dp[maxn][maxn];
//dp[i][j] = true iff substring of length i ending at j is a palindrome

void solve(){
	string s;
	cout << "s: ";
	cin >> s;
	int n = s.size();
	int l = 0, r = 0;
	for (int j = 0; j < n; j++){
		dp[0][j] = dp[1][j] = true;
	}
	for (int i = 2; i <= n; i++){
		for (int j = i - 1; j < n; j++){
			if (s[j] == s[j - i + 1] && dp[i - 2][j - 1]){
				dp[i][j] = true;
				r = j;
				l = j - i + 1;
			}
		}
	}
	cout << "Longest palindromic substring of s: ";
	for (int i = l; i <= r; i++){
		cout << s[i];
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
