#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include<bits/stdc++.h>
using namespace std;

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

template<typename T>
struct SegTree {
    int n;
    vector<T> dat;

         
    SegTree(int siz) {
        n = 1;
        while(n < siz) n <<= 1;
        dat.resize(n * 2, T::ide());
    }

    private:
         
        T query(int l, int r) {
            T L = T::ide(), R = T::ide();
            l += n - 1, r += n - 1;
            while(l < r) {
                if(l & 1) L = op(L, dat[l++]);
                if(r & 1) R = op(dat[--r], R);
                l >>= 1, r >>= 1;
            }  
            return  op(L, R);
        }

    
    public:

        void set(int pos, T x) {
            pos += n-1;
            dat[pos] = x;
        }
          
        void init() {
            for(int i = n-1; i >= 1; i--)  dat[i] = op(dat[i<<1], dat[i<<1|1]);
        }
          
        void change(int pos, T x) {
            pos += n - 1;
            dat[pos] = update(dat[pos], x);
            while(pos >= 2) {
                pos >>= 1;
                dat[pos] = op(dat[pos<<1], dat[pos<<1|1]);
            }
        }
         
        T get(int l, int r) {// [l, r]の演算結果。
            return query(l, r+1);
        }

        T operator[](int pos) {
            return dat[pos + n - 1];
        }
         
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