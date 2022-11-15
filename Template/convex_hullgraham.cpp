#include<bits/stdc++.h>
using namespace std;

struct pt {
    long long x, y;
    bool operator < (const pt &oth) {return (x == oth.x ? y < oth.y : x < oth.x);}
    bool operator == (const pt &oth) {return (x == oth.x && y == oth.y);}
    bool operator != (const pt &oth) {return (x != oth.x || y != oth.y);}
    pt operator - (const pt &oth) {return pt{x - oth.x, y - oth.y};}
    pt operator + (const pt &oth) {return pt{x + oth.x, y + oth.y};}
    void operator -= (const pt &oth) {x -= oth.x, y -= oth.y;}
    void operator += (const pt &oth) {x += oth.x, y += oth.y;}
    long long operator * (const pt &oth) {return x * oth.y -  y * oth.x;}
    void read() {cin >> x >> y;}
    void print() {cout << x << ' ' << y;}
};

pt org;

long long lenSquare (pt A, pt B) {
    B -= A;
    return (B.x * B.x + B.y + B.y);
}

long long cross (pt O, pt A, pt B) {
    A -= O;
    B -= O;
    return A * B;
}

vector<pt> ConvexHull (vector<pt> vec) {
    sort(vec.begin(), vec.end());
    org = vec.front();
    vector<pt> p;
    for (pt points : vec) {
        if (points != org) {
            p.push_back(points);
        }
    }
    sort(p.begin(), p.end(), [&] (const pt &A, const pt &B) {
        if (!cross(org, A, B)) return lenSquare(org, A) < lenSquare(org, B);
        return cross(org, A, B) > 0;
    });
    vector<pt> res;
    res.push_back(org);
    for (pt p3 : p) {
        while (res.size() > 1) {
            pt p2 = res.back(); res.pop_back();
            pt p1 = res.back();
            if (cross(p1, p2, p3) > 0) {
                res.push_back(p2);
                break;
            }
        }
        res.push_back(p3);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<pt> a(n);
        for (int i = 0; i < n; i++) a[i].read();

        vector<pt> res = ConvexHull(a);
        cout << res.size() << '\n';
        for (auto P : res) {
            cout << P.x << ' ' << P.y << '\n';
        }
        cout << '\n';
    }

    return 0;
}
