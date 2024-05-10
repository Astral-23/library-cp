#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include<bits/stdc++.h>
using namespace std;
#include "../Utilities/modint998.hpp"
#include "../DataStructures/SegTree.hpp"

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
    int test = 100;
     SegTree<Monoid> seg(N);
    for(int i = 1; i <= N; i++) {
        mint a, b;
        cin >> a >> b;
        seg.set(i, Monoid(a, b));
    }
	seg.init();


    while(Q--) {
        int type;
        cin >> type;
        int x, y, z;
        cin >> x >> y >> z;
        x++;
        if(type == 0) {
            seg.change(x, Monoid(y, z));
        }
        else {
            
            auto [a, b] = seg.get(x, y);
            cout << a * z + b << '\n';
        }
    }
    
}