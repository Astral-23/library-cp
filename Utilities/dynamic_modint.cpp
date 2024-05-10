struct mint{
    long long x;
    mint(long long _x=0) : x((_x%mod+mod)%mod){}
    long long val()  {return x;}
    mint& operator+=(const mint& a)  {if((x += a.x) >= mod) x -= mod;return *this;}
    mint& operator-=(const mint& a)  {if((x += mod - a.x) >= mod) x -= mod;return *this;}
    mint& operator*=(const mint& a)  {(x *= a.x) %= mod;return *this;}
    mint& operator/=(const mint& a) {return (*this) *= a.inv();}
    mint& operator++() noexcept {return *this += 1;}
    mint& operator--() noexcept {return *this -= 1;}
    mint operator++(int) {mint tmp = *this; ++*this; return tmp;}
    mint operator--(int) {mint tmp = *this; --*this; return tmp;}
    mint inv() const {return pow(mod-2);}
    friend mint operator+(const mint&  t, const mint& a)  {mint tmp = t; return tmp += a;}
    friend mint operator-(const mint&  t, const mint& a)  {mint tmp = t; return tmp += (a * -1);}
    friend mint operator*(const mint&  t, const mint& a)  {mint tmp = t; return tmp *= a;}
    friend mint operator/(const mint&  t, const mint& a)  {assert(a.x != 0) ; return a.inv() *=  t;}
    mint pow(const long long& y) const {
        assert(y >= 0);
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
   bool operator<(const mint& a) const {return x < a.x;}

};

/*
@brief 任意modのmodint(mod < 2 ^ 32)
*/