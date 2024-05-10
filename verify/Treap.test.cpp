#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../Utilities/modint998.hpp"
#include "../DataStructures/Treap.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'

 struct Monoid {

    mint a;
   
     Monoid(){}
       
     Monoid(mint _a) : a(_a) {}
   
     friend Monoid op(const Monoid& l, const Monoid& r) {
       return l.a + r.a;
     }

     static Monoid ide() {
        return mint(0);
    }
   

};

struct E {
    mint p, b;
   
     E(){}
       
     E(mint _p, mint _x) {
       p = _p;
       b = _x;
     }
   
     friend E op(const E& l, const E& r) {
       E res;
       res.p = l.p * r.p;
       res.b = r.p * l.b + r.b;
       return res;
     }
   
    static E ide() {
        return E(1, 0);
    }

    bool operator==(const E& x) const {return (p == x.p) && (b == x.b);}
    bool operator!=(const E& x) const {return (p != x.p) || (b != x.b);}
};


Monoid fx(const Monoid& l, const E& r, long long len) {
     return r.p * l.a + r.b * len;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Treap<Monoid, E> tr(fx);
    ll N, Q;
    cin >> N >> Q;
    for(int i = 0; i <= N-1; i++) {
        mint a;
        cin >> a;
        tr.insert(i, a);
    }

    

    while(Q--) {
        int type;
        cin >> type;
        if(type == 0) {
            ll i, x;
            cin >> i >> x;
           tr.insert(i, Monoid(x));
            N++;
        }
        else if(type==1) {
            int i;
            cin >> i;
            tr.erase(i);
            N--;
        }
        else if(type==2) {
            ll l, r;
            cin >> l >> r;
            r--;
            tr.reverse(l,r);
        }
        else if(type==3) {
            ll l, r;
            mint b, c;
            cin >> l >> r >> b >> c;
            r--;
            tr.change(l, r, E(b, c));
        }
        else {
            ll l, r;
            cin >> l >> r;
            r--;
            cout << tr.get(l, r).a << " ";
        }
    }

  /*

    while(Q--) {
        ll type;
        cin >> type;
        if(type == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            tr.change(l, r-1, E(b, c));
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << tr.get(l, r-1).a << " ";
        }
    }*/


    
    
    
    
}