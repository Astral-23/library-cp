struct P {
	using ll = long long;
	ll x, y;
	P () {}
	P (ll _x, ll _y) : x(_x), y(_y) {}
	bool operator<(const P& a) {
		if(x != a.x) return x < a.x;
		else return y < a.y;
	}
};
