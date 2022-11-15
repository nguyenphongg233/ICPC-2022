/**
*  Author : nguyenphong233 
*  Date   :
**/

#include<bits/stdc++.h>

// My Template 

using namespace std;

#define ii pair<int,int> 
#define vi vector<int>

#define X first
#define Y second

const long long MAX = (int)1e5 + 5;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;

void gettime(){
	time_t now = time(0);
	char* x = ctime(&now);
	cerr<<"Right Now Is : "<<x<<"\n";
}

void faster(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
}
void read(){
	
	gettime();
	faster();

	if(ifstream("task.inp")){
		freopen("task.inp","r",stdin);
		freopen("task.out","w",stdout);
	}
	
}

// End Of My template 
// Keep Watching 

const int N = 1004;

int n, m, h[N][N];

signed main(){
	
	read();
	
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> h[i][j];
		int hang = 0, cot = 0;
		for (int i = 1; i <= n; i++) {
			bool ok = 1;
			for (int j = 2; j <= m; j++) {
				if (h[i][j] != h[i][1]) {
					ok = 0;
					break;
				}
			}
			if (ok) hang++;
		}
		for (int j = 1; j <= m; j++) {
			bool ok = 1;
			for (int i = 2; i <= n; i++) {
				if (h[i][j] != h[1][j]) {
					ok = 0;
					break;
				}
			}
			if (ok) cot++;
		}
		cout << cot * hang << '\n';
	}
	
	
}