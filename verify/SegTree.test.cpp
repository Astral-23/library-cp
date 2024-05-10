#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include<bits/stdc++.h>
using namespace std;
#include "../Utilities/modint998.hpp"
#include "../DetaStructures/SegTree.hpp"

struct mint{//998244353
   long long x;
   static const long long mod = 998244353;
   mint(long long _x=0) noexcept : x((_x%mod+mod)%mod){}
   long long val() const noexcept {return x;}
   mint& operator+=(const mint& a) noexcept {if((x += a.x) >= mod) x -= mod;return *this;}
   mint& operator-=(const mint& a) noexcept {if((x += mod - a.x) >= mod) x -= mod;return *this;}
   mint& operator*=(const mint& a) noexcept {(x *= a.x) %= mod;return *this;}
   mint& operator/=(const mint& a) {return (*this) *= a.inv();}
   mint& operator++() noexcept {return *this += 1;}
   mint& operator--() noexcept {return *this -= 1;}
   mint operator++(int) {mint tmp = *this; ++*this; return tmp;}
   mint operator--(int) {mint tmp = *this; --*this; return tmp;}
   mint inv() const {return pow(mod-2);}
   friend mint operator+(const mint&  t, const mint& a)  {mint tmp = t; return tmp += a;}
   friend mint operator-(const mint&  t, const mint& a)  {mint tmp = t; return tmp += (a * -1);}
   friend mint operator*(const mint&  t, const mint& a)  {mint tmp = t; return tmp *= a;}
   friend mint operator/(const mint&  t, const mint& a)  {return a.inv() *=  t;}
   mint pow(const long long& y) const {
    if(!y) return 1;
    mint res = pow(y >> 1);
    res *= res;
    if(y & 1) res *= *this;
    return res;
  }
   friend istream& operator>>(istream& is, mint& a) { return is >> a.x;}
   friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
   bool operator==(const mint& a) const {return x == a.x;}
   bool operator!=(const mint& a) const {return x != a.x;}
};



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