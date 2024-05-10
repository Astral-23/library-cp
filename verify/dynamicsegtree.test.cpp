#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include<bits/stdc++.h>
using namespace std;
#include "../Utilities/modint998.hpp"
#include "../DataStructures/DynamicSegTree.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'

struct Monoid {
    mint a, b;
    
    Monoid(){}
    Monoid(mint _a, mint _b) : a(_a), b(_b){};

    friend Monoid op(const Monoid& l, const Monoid& r) {
        Monoid res;
        res.a = l.a * r.a;
        res.b = r.a * l.b + r.b;
        return res;
    } 
    friend Monoid update(const Monoid& l, const Monoid& x) {
        return x;
    }


	static Monoid ide() {
		return Monoid(1, 0);

	}
};





int main() {
	ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    DynamicSegTree<Monoid, int> seg(-250000, 250000);
    for(int i = 0; i < N; i++) {
        mint a, b;
        cin >> a >> b;
        seg.change(i-250000, Monoid(a, b));
    }

    while(Q--) {
        int type;
        cin >> type;
        int x, y, z;
        cin >> x >> y >> z;
        x -= 250000;
        if(type == 0) {
            seg.change(x, Monoid(y, z));
        }
        else {
            y -= 250000;
            auto [a, b] = seg.get(x, y-1);
            cout << a * z + b << '\n';
        }
    }
}