#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505;
const int L = 10;
const int inf = 1e9 + 7;

int n, m, t[N][N][L][L], lg[N];

int get (int x, int y, int u, int v) {
    int k = lg[u - x + 1];
    int l = lg[v - y + 1];
    return max(
                max(t[x][y][k][l], t[x][v - (1 << l) + 1][k][l]),
                max(t[u - (1 << k) + 1][y][k][l], t[u - (1 << k) + 1][v - (1 << l) + 1][k][l])
           );
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 2; i < N; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> t[i][j][0][0];
            }
        }
        for (int k = 0; (1 << k) <= n; k++) {
            for (int l = 0; (1 << l) <= m; l++) {
                for (int i = 1; i + (1 << k) - 1 <= n; i++) {
                    for (int j = 1; j + (1 << l) - 1 <= m; j++) {
                        if (k == 0 && l == 0) 
                            continue;
                        else if (k == 0)
                            t[i][j][0][l] = max(t[i][j][0][l - 1], t[i][j + (1 << (l - 1))][0][l - 1]);
                        else if (l == 0)
                            t[i][j][k][0] = max(t[i][j][k - 1][0], t[i + (1 << (k - 1))][j][k - 1][0]);
                        else {
                            t[i][j][k][l] = max(
                                 max(t[i][j][k - 1][l - 1], t[i][j + (1 << (l - 1))][k - 1][l - 1]),
                                 max(t[i + (1 << (k - 1))][j][k - 1][l - 1], t[i + (1 << (k - 1))][j + (1 << (l - 1))][k - 1][l - 1])
                            );
                        }
                    }
                }
            }
        }
        // do smth ...
    }
    
    return 0;
}