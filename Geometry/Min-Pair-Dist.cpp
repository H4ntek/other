#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const lli INF = 9e18 + 7;

struct P{
	lli x, y;

	void read(){
		cin >> x >> y;
	}
	void write(){
		cout << "(" << x << ", " << y << ")\n";
	}
	lli operator *(const P &b){
		return x * b.y - y * b.x;
	}
};

bool by_x(const P &p1, const P &p2){
	return p1.x < p2.x;
}

bool by_y(const P &p1, const P &p2){
	return p1.y < p2.y;
}

lli sq(const lli &a){
	return a * a;
}

lli dist(const P &A, const P &B){
	return sq(A.x - B.x) + sq(A.y - B.y);
}

lli min_pair_dist(vector <P> points){

	int n = points.size();
	if (n <= 1){
		return INF;
	}

	vector <P> left, right;
	for (int i = 0; i < n / 2; i++){
		left.push_back(points[i]);
	}
	for (int i = n / 2; i < n; i++){
		right.push_back(points[i]);
	}
	lli mid_x = left.back().x;
	lli min_left = min_pair_dist(left);
	lli min_right = min_pair_dist(right);
	lli min_overall = min(min_left, min_right);

	// pasek
	vector <P> stripe;
	for (int i = 0; i < (int) left.size(); i++){
		if (sq(mid_x - left[i].x) < min_overall){
			stripe.push_back(left[i]);
		}
	}
	for (int i = 0; i < (int) right.size(); i++){
		if (sq(right[i].x - mid_x) < min_overall){
			stripe.push_back(right[i]);
		}
	}

	sort(stripe.begin(), stripe.end(), by_y);
	for (int i = 0; i < (int) stripe.size(); i++){
		for (int j = i + 1; j < (int) stripe.size() && sq(stripe[j].y - stripe[i].y) < min_overall; j++){
			min_overall = min(min_overall, dist(stripe[i], stripe[j]));
		}
	}

	return min_overall;
}

void solve(){
	int n;
	cin >> n;
	vector <P> points(n);
	for (int i = 0; i < n; i++){
		points[i].read();
	}
	sort(points.begin(), points.end(), by_x);
	lli ans = min_pair_dist(points);
	cout << ans << "\n";
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
