
template<typename T>
struct BIT {
    int N;
    vector<T> dat;
	BIT(){}
    BIT(int _N) : N(_N) {
        dat.resize(N+1, 0);
    }

	void set(int pos, T val) {dat[pos] = val;}

	void init() {
		for(int x = 1; x < N; ++x) if(x + (x & -x) <= N) dat[x + (x&-x)] += dat[x];
	}

    void add(int pos, T val) {
        for(int x = pos; x <= N; x += x & -x) dat[x] += val;
    }

    T get(int r) {
        T res = 0;
        for(int x = r; x > 0; x -= x & -x) res += dat[x];
        return res;
    }
    
    T get(int l, int r) {
		T res = get(r);
		if(l!=1) res -= get(l-1);
		return res;
	}

};

/*
@brief : BIT
*/