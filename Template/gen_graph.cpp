#include<bits/stdc++.h>
using namespace std;
#define taskname ""
#define int long long
#define bend(a) begin(a), end(a)
#define db(val) "["#val" = "<<(val)<<"] "

const int N = 1005;

int n = 10;
int m = 9;
int w = 20;
bool weighted = 1;
int p[N];

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint (int l, int r) {
  return uniform_int_distribution <int> (l,r) (rng);
}

struct E {
    int u, v, w;  
    bool operator < (const E oth) const {
        return w < oth.w;
    }
};

/// DSU ///
int root (int u) {
    if (p[u] == u) return u;
    return p[u] = root(p[u]);
}

bool union_set (int u, int v) {
    u = root(u);
    v = root(v);
    if (u != v) {
        p[u] = v;
        return true;
    }
    return false;
}
/// DSU ///

vector<E> edge;
vector<E> vec;

void create_tree() {
    for (int i = 0; i < N; i++) p[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
        	if (i == j) continue;
            vec.push_back({i, j, randint(1, w)});
        }
    }
    random_shuffle(bend(vec));
    for (auto [u, v, c] : vec) {
        if (union_set(u, v)) {
            edge.push_back({u, v, c});
        }
    }
}

void create_graph() {
    set<pair<int, int>> have;
    for (auto [u, v, c] : edge) {
        have.insert({u, v});
        have.insert({v, u});
    }
    while (edge.size() < m) {
        int i = randint(0, (int) vec.size() - 1);
        if (!have.count({vec[i].u, vec[i].v})) {
            edge.push_back(vec[i]);
            have.insert({vec[i].u, vec[i].v});
            have.insert({vec[i].v, vec[i].u});
        }
    }
}

void print_graph() {
    for (auto [u, v, c] : edge) {
        cout << u << ' ' << v << ' ';
        if (weighted) {
            cout << c;
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    if (ifstream(taskname".inp")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    
    cout << n << ' ' << m << '\n';
    create_tree();
    // create_graph();
    print_graph();
        
    return 0;
}