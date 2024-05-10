
template<typename X, typename E>
struct LazySegTree {
    using FX = function<X(X, E, long long)>;//Xに作用素Mを作用させる
    
    int n;
    int siz;
    FX fx; 
    vector<X> dat;
    vector<E> lazy;
    LazySegTree(int _siz, FX _fx) : siz(_siz),  fx(_fx) {
        n = 1;
        while(n < siz) n <<= 1;
        dat.assign(n * 2, X::ide());
        lazy.assign(n * 2, E::ide());
    }

    private:
        void eval(int k, int len) {
            if(lazy[k] == E::ide()) return;
            if(k < n) {
              lazy[k<<1] = op(lazy[k<<1], lazy[k]);
              lazy[k<<1|1] = op(lazy[k<<1|1], lazy[k]);
            }
            dat[k] = fx(dat[k], lazy[k], len);
            lazy[k] = E::ide();
        }    

        X query(int a, int b, int l, int r, int k) {
            eval(k,r-l);
            if(r <= a || b <= l) return X::ide();
            if(a <= l && r <= b) return dat[k];
            int mid = (l + r)>>1;
            X L = query(a, b, l, mid, k<<1);
            X R = query(a, b, mid, r, k<<1|1);
            return op(L, R);
        }  

        void update(int a, int b, E m, int l, int r,  int k) {//[a, b) := クエリ区間  [l, r) := 今見ている区間
            eval(k, r-l);
            if(r <= a || b <= l) return;
            if(a <= l && r <= b) {
                lazy[k] = op(lazy[k], m);
                eval(k, r-l);
            }
            else {
                int mid = (l + r)>>1;
                update(a, b, m, l, mid, k<<1);
                update(a, b, m, mid, r, k<<1|1);
                dat[k] = op(dat[k<<1], dat[k<<1|1]);
            }
        }   
    
    public:

        void set(int i, X x) {
            dat[i + n - 1] =  x;
        }    

        void init() {
            for(int i = n-1; i >= 1; i--) {
                dat[i] = op(dat[i<<1], dat[i<<1|1]);
            }
        }    
    
        void change(int l, int r, E m) {
            update(l, r + 1, m, 1, n + 1, 1);
        }

        X get(int l, int r) {
          return query(l, r + 1, 1, n + 1, 1);
        }

        void dump() {
            for(int i = 1; i <= siz; i++) {
                cout << get(i, i) << " ";//適宜直す。
            }
            cout << endl;
        }
};    

using ll = long long;

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

/*
@brief 遅延セグメント木
*/