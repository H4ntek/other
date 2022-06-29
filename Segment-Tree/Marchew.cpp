#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

#define ff first
#define ss second

const int MAXN = 2e5 + 3, LOG = 19;
const lli INF = 9e18 + 3;

lli a[MAXN], lazy[1 << LOG][2];
pair <lli, int> st[1 << LOG][2]; // {max, pos}
int in_set[MAXN];

void build(int id, int si, int ss, int se){
    if (ss == se){
        st[si][id] = {a[ss], ss};
        return;
    }
    int mid = (ss + se) / 2;
    build(id, 2 * si, ss, mid);
    build(id, 2 * si + 1, mid + 1, se);
    st[si][id] = max(st[2 * si][id], st[2 * si + 1][id]);
}

void propagate(int id, int si, int ss, int se, lli val){
    st[si][id].ff += val;
    if (ss != se){
        lazy[2 * si][id] += val;
        lazy[2 * si + 1][id] += val;
    }
}

pair <lli, int> query(int id, int si, int ss, int se, int qs, int qe){ 
    if (lazy[si][id]){
        propagate(id, si, ss, se, lazy[si][id]);
        lazy[si][id] = 0;
    }
    if (se < qs || ss > qe){
        return {-INF, -1};
    }
    if (ss >= qs && se <= qe){
        return st[si][id];
    }
    int mid = (ss + se) / 2;
    return max(query(id, 2 * si, ss, mid, qs, qe), query(id, 2 * si + 1, mid + 1, se, qs, qe));
}

void update(int id, int si, int ss, int se, int us, int ue, lli val){
    if (lazy[si][id]){
        propagate(id, si, ss, se, lazy[si][id]);
        lazy[si][id] = 0;
    }
    if (se < us || ss > ue){
        return;
    }
    if (ss >= us && se <= ue){
        propagate(id, si, ss, se, val);
        return;
    }
    int mid = (ss + se) / 2;
    update(id, 2 * si, ss, mid, us, ue, val);
    update(id, 2 * si + 1, mid + 1, se, us, ue, val);
    st[si][id] = max(st[2 * si][id], st[2 * si + 1][id]);
}

// st[*][0] - druga klasa, st[*][1] - pierwsza

void solve(){
    int n, q, l, r, pierwsza_i_druga = 0, pierwsza = 0;
    lli x, g1, g2;
    pair <lli, int> mx;
    cin >> n >> q >> g2 >> g1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(0, 1, 1, n);
    build(1, 1, 1, n);
    while (q--){
        cin >> l >> r >> x;
        update(0, 1, 1, n, l, r, x);
        update(0, 1, 1, n, 1, n, 1);
        update(1, 1, 1, n, l, r, x);
        update(1, 1, 1, n, 1, n, 1);

        mx = query(0, 1, 1, n, 1, n);
        while (mx.ff >= g2){
            update(0, 1, 1, n, mx.ss, mx.ss, -INF);
            pierwsza_i_druga++;
            mx = query(0, 1, 1, n, 1, n);
        }
        mx = query(1, 1, 1, n, 1, n);
        while (mx.ff >= g1){
            update(1, 1, 1, n, mx.ss, mx.ss, -INF);
            pierwsza++;
            mx = query(1, 1, 1, n, 1, n);
        }
        cout << pierwsza << " " << pierwsza_i_druga - pierwsza << "\n";
    }
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
