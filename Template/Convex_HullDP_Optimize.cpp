#include<bits/stdc++.h>
using namespace std;
using ll = long long;

using ld = long double;
struct line {
    ll A, B;
    ll cord_y (ll x) {
        return x * A + B;
    }
    ld ins (line oth) {
        return (long double) (oth.B - B) / (A - oth.A);
    }
    bool operator < (const line &oth) const {
        return (A == oth.A ? B < oth.B : A < oth.A);
    }
};

struct convex_hull {
    // bao loi max, min trong truong hop canh them vao theo he so goc tang dan
    bool find_maximum;
    vector<line> hull;
    
    convex_hull() {}
    convex_hull (bool state) {
        find_maximum = state;
    }
  
    bool bad (line l1, line l2, line l3) {
        return (find_maximum ? l1.ins(l3) < l1.ins(l2) : l1.ins(l3) > l1.ins(l2));
    }
    
    void add (line d) {
        if (!find_maximum) {
            d.A = 0LL - d.A;
            d.B = 0LL - d.B;
        }
        int m = (int) hull.size();
        while (m >= 2) {
            if (!bad(hull[m - 2], hull[m - 1], d)) break;
            hull.pop_back();
            m--;
        }
        hull.push_back(d);
    }
    
    ll query (ll x) {
        int lo = 0, hi = (int) hull.size() - 2, p = (int) hull.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (hull[mid].cord_y(x) < hull[mid + 1].cord_y(x)) lo = mid + 1;
            else p = mid, hi = mid - 1;
        }
        return (find_maximum ? 1LL : -1LL) * hull[p].cord_y(x);
    }

};

convex_hull H(1), T(0);


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    convex_hull A;
    A = convex_hull(0);
    
    int x, y;
    while (cin >> x >> y) {
        H.add({x, y});
    }
    for (auto [x, y] : H.hull) {
        cout << x << ' ' << y << '\n';
    }
    
    return 0;
}

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};