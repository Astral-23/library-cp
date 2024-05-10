
template<int mod>
struct modint{
    long long x;
    modint(long long _x=0) noexcept : x((_x%mod+mod)%mod){}
    long long val() const noexcept {return x;}
    modint& operator+=(const modint& a) noexcept {if((x += a.x) >= mod) x -= mod;return *this;}
    modint& operator-=(const modint& a) noexcept {if((x += mod - a.x) >= mod) x -= mod;return *this;}
    modint& operator*=(const modint& a) noexcept {(x *= a.x) %= mod;return *this;}
    modint& operator/=(const modint& a) {return (*this) *= a.inv();}
    modint& operator++() noexcept {return *this += 1;}
    modint& operator--() noexcept {return *this -= 1;}
    modint operator++(int) {modint tmp = *this; ++*this; return tmp;}
    modint operator--(int) {modint tmp = *this; --*this; return tmp;}
    modint inv() const {return pow(mod-2);}
    friend modint operator+(const modint&  t, const modint& a)  {modint tmp = t; return tmp += a;}
    friend modint operator-(const modint&  t, const modint& a)  {modint tmp = t; return tmp += (a * -1);}
    friend modint operator*(const modint&  t, const modint& a)  {modint tmp = t; return tmp *= a;}
    friend modint operator/(const modint&  t, const modint& a)  {assert(a.x != 0) ; return a.inv() *=  t;}
    modint pow(const long long& y) const {
        if(!y) return 1;
        modint res = pow(y >> 1);
        res *= res;
        if(y & 1) res *= *this;
        return res;
    }
    friend istream& operator>>(istream& is, modint& a) { return is >> a.x;}
    friend ostream& operator<<(ostream& os, const modint& a) { return os << a.x;}
    bool operator==(const modint& a) const {return x == a.x;}
    bool operator!=(const modint& a) const {return x != a.x;}
    bool operator<(const modint& a) const {return x < a.x;}
};
using mint = modint<998244353>;
/*
@brief modint998244353
*/