/**
*  Author : nguyenphong233 
*  Date   :
**/

#include<bits/stdc++.h>

// My Template 

using namespace std;

void faster(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
}

const int N = 2e5 + 5;

struct que {
	char t;
	int s, u, v;
	void Print() {
		cout << t << ' ' << s << ' ' << u <<' ' << v << endl;
	}
};

struct Data {
	int u, v, id;	
};

int n, q, pa[N];
bool res[N];
vector<Data> g[N];
vector<que> Q;

int root (int x) {
	return (pa[x] == 0 ? x : pa[x] = root(pa[x]));
}

bool unite (int u, int v, bool noi) {
	u = root(u);
	v = root(v);
	if (u == v) return 1;
	if (noi) pa[u] = v;
	return 0;
}

signed main(){
	
	faster();
	
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		char t;
		cin >> t;
		int s, u, v;
		if (t == 'A' || t == '?') cin >> u >> v;
		if (t == 'Q') {
			cin >> s >> u >> v;
			g[s].push_back({u, v, i});
		}
		Q.push_back({t, s, u, v});
	}
	int cnt = 1;
	for (int i = 0; i < q; i++) {
		// cout << "tv " << i << ":\n";
		if (Q[i].t == 'A') {
			unite(Q[i].u, Q[i].v, 1);
			// Q[i].Print();
		}
		if (Q[i].t == '?') res[i] = unite(Q[i].u, Q[i].v, 0);
		if (Q[i].t == 'C') {
			// cout << "#" << cnt << '\n';
			while (!g[cnt].empty()) {
				Data X = g[cnt].back();
				res[X.id] = unite(X.u, X.v, 0);
				// cout << X.u << ' ' << X.v << ' ' << X.id << '\n';
				g[cnt].pop_back();
			}
			cnt++;
		}
	}
	for (int i = 0; i < q; i++) if (Q[i].t == '?' || Q[i].t == 'Q') cout << (res[i] ? "Y" : "N");
	
}