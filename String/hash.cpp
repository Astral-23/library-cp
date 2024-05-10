
long long MOD = (1LL << 61) -1;
struct hint{//mint for rhash
    long long x;
    hint(long long _x=0) : x((_x%MOD+MOD)%MOD){}
    long long val()  {return x;}
    hint& operator+=(const hint& a)  {if((x += a.x) >= MOD) x -= MOD;return *this;}
    hint& operator-=(const hint& a)  {if((x += MOD - a.x) >= MOD) x -= MOD;return *this;}
    hint& operator*=(const hint& a)  {
        __int128_t t = (__int128_t)(this -> x) * a.x;//キャスト忘れがち
        t %= MOD; if(t < 0) t += MOD;
        *this = t;
        return *this;
    }
    hint& operator/=(const hint& a) {return (*this) *= a.inv();}
    hint& operator++() noexcept {return *this += 1;}
    hint& operator--() noexcept {return *this -= 1;}
    hint operator++(int) {hint tmp = *this; ++*this; return tmp;}
    hint operator--(int) {hint tmp = *this; --*this; return tmp;}
    hint inv() const {return pow(MOD-2);}
    friend hint operator+(const hint&  t, const hint& a)  {hint tmp = t; return tmp += a;}
    friend hint operator-(const hint&  t, const hint& a)  {hint tmp = t; return tmp += (a * -1);}
    friend hint operator*(const hint&  t, const hint& a)  {hint tmp = t; return tmp *= a;}
    friend hint operator/(const hint&  t, const hint& a)  {assert(a.x != 0) ; return a.inv() *=  t;}
    hint pow(const long long& y) const {
        assert(y >= 0);
        if(!y) return 1;
        hint res = pow(y >> 1);
        res *= res;
        if(y & 1) res *= *this;
        return res;
    }
   friend istream& operator>>(istream& is, hint& a) { return is >> a.x;}
   friend ostream& operator<<(ostream& os, const hint& a) { return os << a.x;}
   bool operator==(const hint& a) const {return x == a.x;}
   bool operator!=(const hint& a) const {return x != a.x;}
   bool operator<(const hint& a) const {return x < a.x;}
};


struct base_rhash {
    int MAX_TYPE = 100;
    hint B = rand()%200 + MAX_TYPE;//文字の種類数より大きければ良い。
    vector<hint> pb;

    base_rhash(int siz) {
        unsigned int now = time(NULL);
        srand(now);
        pb.resize(siz+1);
        pb[0] = 1;
        for(int i = 1; i <= siz; i++) {
            pb[i] = pb[i-1] * B;
        }
    }
    //ローリングハッシュを使うためのBaseとそれの累乗を計算する。sizには、文字列の最大長を入れる。
};base_rhash brh(最大文字列長);



struct rhash {
    //depend on base_rhash
    //このままセグ木に乗る
    hint h;
    int len;
    rhash() : h(0), len(0){}
    rhash(hint _h, int _len) : h(_h), len(_len){}

    public: 
        friend bool operator==(const rhash& l, const rhash& r) {return l.h == r.h && l.len == r.len;}
        friend bool operator!=(const rhash& l, const rhash& r) {return !(l == r);}

        friend rhash op(const rhash& l, const rhash& r) {//lとrをこの順で結合する
            rhash res;
            res.h = l.h*brh.pb.at(r.len) + r.h;//brhで確保した文字列長が足りない時にエラーを吐いて欲しい
            res.len = l.len + r.len;
            return res;
        }
    
        friend rhash update(const rhash& l, const rhash& x) {//代入
            return x;
        }

        static rhash ide() {
            return rhash(0, 0);
        }

};


struct rhash_string {
    vector<rhash> H;//0-indexedで、res[i] := [0, i]文字目の文字列に対応するハッシュ
    rhash_string(){}

    rhash_string(string& S) {
        H.resize(S.size(), def);
        H[0].h = S[0] - 'a' + 1;
        H[0].len = 1;
        for(int i = 1; i < int(S.size()); i++) {
          H[i].h = H[i-1].h * brh.B + S[i] - 'a' + 1;
          H[i].len = 1 + H[i-1].len;
        }
    }

    rhash get(int l, int r) {//1-indexedで、[l, r]に対応するハッシュを返す。
        l--, r--;
        if(l > r) return def;
        rhash res = H[r];
        if(l != 0) res.h = res.h - brh.pb[r-l+1] * H[l-1].h;
        res.len = r-l+1;
        return res;
    }
};

rhash cal_rhash(string& S) {
    rhash res;
    for(int i = 0; i < int(S.size()); i++) {
        res.h = res.h * brh.B + S[i] - 'a'+1;
    }
    res.len = S.size();
    return res;
}

rhash cal_rhash(char s) {
    return rhash(s - 'a' + 1, 1);
}

/*
@brief ローリングハッシュの型
*/