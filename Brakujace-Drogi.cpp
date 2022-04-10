#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int MAXN = 1e4 + 3;

vector <int> adj[MAXN], adj_t[MAXN], adj_comp[MAXN];
int comp_size[MAXN], comp[MAXN];
bool vis[MAXN], has_in[MAXN], has_out[MAXN];

int comp_no;
vector <int> postorder;

void DFS_postorder(int v){
    vis[v] = true;
    for (int child : adj[v]){
        if (!vis[child]){
            DFS_postorder(child);
        }
    }
    postorder.push_back(v);
}

void DFS_t(int v){
    comp[v] = comp_no;
    comp_size[comp_no]++;
    for (int child : adj_t[v]){
        if (comp[child] == 0){
            DFS_t(child);
        }
        else if (comp[child] != comp_no){
            adj_comp[comp[child]].push_back(comp_no);
            has_in[comp_no] = true;
            has_out[comp[child]] = true;
        }
    }
}

void solve(){
    int n, m, a, b;
    cin >> n >> m;
    set <pair <int, int>> st;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        if (a != b){
			st.insert({a, b});        	
		}
    }
    set <pair <int, int>> :: iterator it;
    for (it = st.begin(); it != st.end(); it++){
        adj[(*it).first].push_back((*it).second);
        adj_t[(*it).second].push_back((*it).first);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            DFS_postorder(i);
        }
    }
    reverse(postorder.begin(), postorder.end());
    for (int v : postorder){
        if (comp[v] == 0){
            comp_no++;
            DFS_t(v);
        }
    }
    int total_in = 0, total_out = 0;
    for (int i = 1; i <= comp_no; i++){
		total_in += has_in[i];
		total_out += has_out[i];
	}
	cout << (comp_no == 1 ? 0 : max(comp_no - total_in, comp_no - total_out)) << "\n";
}

int main (){
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
