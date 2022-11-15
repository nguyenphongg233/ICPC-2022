/**
*  Author : nguyenphong233 
*  Date   :
**/

#include<bits/stdc++.h>

// My Template 

using namespace std;

void faster() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int N = 2e5 + 5;
const int L = 21;

int n, q, a[N], g[N][L], lg[N], bl;

int get_gcd (int l, int r) {
	int h = lg[r - l + 1];
	return __gcd(g[l][h], g[r - (1 << h) + 1][h]);
}

struct Data {
	int val, l, r;
	bool operator < (const Data &oth) const {
		return val < oth.val;
	}
};

vector<pair<int, int>> v[N];
vector<Data> st[4 * N];

vector<Data> hop (vector<Data> x, vector<Data> y) {
	vector<Data> res;
	for (auto &p : x) res.push_back(p);
	for (auto &p : y) res.push_back(p);
	return res;
}

void build (int x = 1, int L = 1, int R = n) {
	if (L == R) {
		for (auto &p : v[L]) {
			st[x].push_back({p.first, L, p.second});
		}
		return;
	}
	int mid = (L + R) / 2;
	build (x * 2, L, mid);
	build (x * 2 + 1, mid + 1, R);
	st[x] = hop(st[x * 2], st[x * 2 + 1]);
}

int get (int l, int r, int d, int x = 1, int L = 1, int R = n) {
	if (L > r || R < l) return 0;
	if (l <= L && R <= r) {
		int p = lower_bound(st[x].begin(), st[x].end(), {d + 1, -1, -1}) - st[x].begin();
		
	}
}

signed main(){
	
	faster();
    for (int i = 2; i < N; i++) {
        lg[i] = lg[i / 2] + 1;
    }
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		g[i][0] = a[i];
	}
	for (int k = 1; (1 << k) <= n; k++) {
		for (int i = 1; i + (1 << k) - 1 <= n; i++) {
			g[i][k] = __gcd(g[i][k - 1], g[i + (1 << (k - 1))][k - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int pre = i;
		while (pre <= n) {
			int pre_gcd = get_gcd(i, pre);
			v[i].push_back({pre_gcd, pre});
			int lo = pre + 1, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (get_gcd(i, mid) == pre_gcd) {
					pre = mid;
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}
			pre++;
		}
	}
	build();
	for (int i = 0; i < q; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		cout << get(l, r, d) << '\n';
	}
	
}