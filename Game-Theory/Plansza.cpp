#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int INF = 1e9 + 7;

void solve(){
	int N, M, Q, S, p, q;
	cin >> N >> M >> Q >> S;
	bool winning[N + 1][M + 1];
	vector <int> moves_x(S), moves_y(S);
	int min_move_x = INF, min_move_y = INF;
	for (int i = 0; i < S; i++){
		cin >> moves_x[i] >> moves_y[i];
		min_move_x = min(min_move_x, moves_x[i]);
		min_move_y = min(min_move_y, moves_y[i]);
	}

	for (int i = N; i > N - min_move_x; i--){ // dowolny ruch z tych pól konczy sie poza planszą
		for (int j = 1; j <= M; j++){
			winning[i][j] = false;
		}
	}
	for (int j = M; j > M - min_move_y; j--){ // dowolny ruch z tych pól konczy sie poza planszą
		for (int i = 1; i <= N; i++){
			winning[i][j] = false;
		}
	}

	for (int i = N - min_move_x; i >= 1; i--){
		for (int j = M - min_move_y; j >= 1; j--){
			winning[i][j] = false;
			for (int k = 0; k < S; k++){
				if (i + moves_x[k] <= N && j + moves_y[k] <= M){
					if (!winning[i + moves_x[k]][j + moves_y[k]]){ // wygrywająca <==> prowadzi do chociaż jednej przegrywającej
						winning[i][j] = true;
					}
				}
			}
		}
	}

	while (Q--){
		cin >> p >> q;
		cout << (winning[p][q] ? "Wlodzimierz\n" : "Jozef\n");
	}
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
