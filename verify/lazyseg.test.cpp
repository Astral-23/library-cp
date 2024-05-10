#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../Utilities/modint998.hpp"
#include "../DetaStructures/LazySegTree.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'


struct Monoid {
    mint a;
   
    Monoid(){}
      
    Monoid(mint _a) : a(_a) {
      
    }

    friend Monoid op(const Monoid& l, const Monoid& r) {
      return l.a + r.a;
    }

    static Monoid ide() {
       return mint(0);
    }
    
};


struct E {    
    mint a, b;
   
    E(){}
      
    E(mint _a, mint _b) : a(_a), b(_b) {}

    friend E op(const E& l, const E& r) {//rのが新しい。(affine)
        E res;
        res.a = l.a * r.a;
        res.b = r.a * l.b + r.b;
        return res;
      
    }
    static E ide() {
       return E(1, 0);
    }
   
    bool operator==(const E& x) const {return (a == x.a && b == x.b);}
    bool operator!=(const E& x) const {return !(*this == x);}

};




Monoid fx(const Monoid& l, const E& r, long long len) {
     return l.a * r.a + r.b * len;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N+1);
    LazySegTree<Monoid, E> seg(N, fx);

    for(int i = 1; i <= N; i++) cin >> A[i];

    for(int i = 1; i <= N; i++) seg.set(i, mint(A[i]));
    seg.init();
    while(Q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int l, r;
            cin >> l >> r;
            mint b, c;
            cin >> b >> c;
            l++;
            seg.change(l, r, E(b, c));
        }
        else {
            int l, r;
            cin >> l >> r;
            l++;
            cout << seg.get(l,r).a << endl;

        }
    }

}