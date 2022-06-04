#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct P{
    lli x, y;
    void read(){
        cin >> x >> y;
    }
    void write(){
        cout << "(" << x << ", " << y << ")\n";
    }
    lli operator *(const P &p) const {
        return x * p.y - y * p.x;
    }
    P operator -(const P &p) const {
        return P{x - p.x, y - p.y};
    }

    lli orient(const P &A, const P &B) const {
        return (A - *this) * (B - *this);
    }

    bool operator <(const P &p){
        return (x == p.x ? y < p.y : x < p.x);
    }
};

vector <P> conv_hull(vector <P> points){

    if ((int) points.size() <= 3){
        return points;
    }

    vector <P> ch;
    // gora
    for (P p : points){
        while ((int) ch.size() >= 2 && ch[ch.size() - 2].orient(ch[ch.size() - 1], p) > 0){
            ch.pop_back();
        }
        ch.push_back(p);
    }

    ch.pop_back();
    int sz_offset = ch.size();
    reverse(points.begin(), points.end());

    // dol
    for (P p : points){
        while ((int) ch.size() >= sz_offset + 2 && ch[ch.size() - 2].orient(ch[ch.size() - 1], p) > 0){
            ch.pop_back();
        }
        ch.push_back(p);
    }

    ch.pop_back();
    return ch;
}

lli sq(const lli &x){
    return x * x;
}

lli dist(P A, P B){
    return sq(A.x - B.x) + sq(A.y - B.y);
}

lli area(P A, P B, P C){
    return abs(A.orient(B, C));
}

lli calipers(vector <P> ch){
    int n = ch.size();
    if (n == 1){
        return 0;
    }
    if (n == 2){
        return dist(ch[0], ch[1]);
    }

    int k = 1;
    while (area(ch[0], ch[n - 1], ch[(k + 1) % n]) > area(ch[0], ch[n - 1], ch[k])){ // dopoki pole trojkata sie zwieksza
        k++;
    }

    lli ans = 0;
    for (int i = 0, j = k; i <= k && j < n; i++){
        ans = max(ans, dist(ch[i], ch[j]));

        while (j < n && area(ch[i], ch[(i + 1) % n], ch[(j + 1) % n]) > area(ch[i], ch[(i + 1) % n], ch[j])){ // dopoki pole trojkata sie zwieksza
            ans = max(ans, dist(ch[i], ch[(j + 1) % n])); 
            j++;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector <P> points(n);
    for (int i = 0; i < n; i++){
        points[i].read();
    }
    sort(points.begin(), points.end());
    vector <P> ch = conv_hull(points); // wyznaczany zgodnie z wskazowkami

    cout << calipers(ch) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
