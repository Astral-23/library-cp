struct Monoid {
    long long a;
   
    Monoid(){}
      
    Monoid(long long _a) : a(_a) {
      
    }

    friend Monoid op(const Monoid& l, const Monoid& r) {
      return l.a + r.a;
    }

    friend Monoid update(const Monoid& l, const Monoid& r) {
   
    }

    static Monoid ide() {
       return 0LL;
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
@brief Monoidと作用素のテンプレート
*/