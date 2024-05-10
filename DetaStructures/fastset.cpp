struct fastset {
	using ll = long long;
	using ull = unsigned long long;
	int W;
	ll siz;
	vector<int> B = {0, 6, 12, 18, 24, 30, 36, 42};
	vector<ull> mask;
	vector<ull> mask_rev;
	vector<vector<ull>> tr;

	fastset(){}

	fastset(int _W) : W(_W) {
		tr.resize(W);
		mask.resize(65,0);
		mask_rev.resize(65, 18446744073709551615ULL);
		siz = 0;
		for(int i = 0; i < W; i++) {
			tr[i].resize(1ULL << B[W-i-1], 0);
		}
		for(int i = 1; i <= 64; i++) {
			mask[i] = mask[i-1] << 1 | 1;
		}
		for(int i = 63; i >= 0; i--) {
			mask_rev[i] = mask_rev[i+1]<<1;
		}
	}

	private:
	    ull Q(ull x, int w) {//x を 2^w で割った商
	        return x >> w;
	    }

			
	    ull lower_bound__(ull x, int i, ull res) {
	    	if(i<0) return res;
	    	if(res == Q(x, B[i+1])) {
	    		if(tr[i][res] >> (Q(x, B[i])&63) & 1) {	
	    			if((tr[i][res] & mask_rev[63-(Q(x, B[i])&63)]) == 0) return lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[64-(Q(x, B[i])&63)]));
	    			return min(lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[64-(Q(x, B[i])&63)])), lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[63-(Q(x, B[i])&63)])));
	    		}
	    		else {
	    			if((tr[i][res] & mask_rev[63-(Q(x, B[i])&63)]) == 0) return 18446744073709551615ULL;
	    			return lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[63-(Q(x, B[i])&63)]));
	    		}
	    	}
	    	else {
	    		return lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res]));
	    	}
	    }
    
	    ull lower_left_bound__(ull x, int i, ull res) {
	    	if(i<0) return res;
	    	if(res == Q(x, B[i+1])) {
	    		if(tr[i][res] >> (Q(x, B[i])&63) & 1) {		
	    			if((tr[i][res]&mask[(Q(x, B[i])&63)]) == 0) return lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res] & mask[(Q(x, B[i])&63)+1])));
	    			return max(lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)]))),lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)+1]))));
	    		}
	    		else {
	    			if((tr[i][res]&mask[(Q(x, B[i])&63)]) == 0) return 0ULL;
	    			return lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)])));
	    		}
	    	}
	    	else {
	    		return lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res])));
	    	}
	    }

	public:


	    void insert(ll x) {
	    	if(count(x))return;
	    	siz++;
	    	for(int i = W-1; i >= 0; i--) {
	    		tr[i][Q(x, B[i+1])] |= 1ULL << (Q(x, B[i])&63);
	    	}
	    }
    
	    void erase(ll x) {
	    	if(!count(x))return;
	    	siz--;
	    	tr[0][Q(x, 6)] ^= 1ULL << (x&63);
	    	for (int i = 1; i < W; i++) {
	    		ull d = (!tr[i-1][Q(x, B[i])]);
	    		tr[i][Q(x, B[i+1])] ^= d << (Q(x, B[i])&63);
	    	}
	    }
    
	    int count(ll x) {
	    	return tr[0][Q(x, 6)] >> (x&63) & 1;
	    }
    
	    ll min_element() {
			assert(siz!=0);
	    	ull res = 0;
	    	for(int i = W-1; i >= 0; i--) {
	    		res = res << 6 | __builtin_ctzll(tr[i][res]);
	    	}
	    	return res;
	    }
    
	    ll max_element() {
			assert(siz!=0);
	    	ull res = 0;
	    	for(int i = W-1; i >= 0; i--) {
	    		res = res << 6 | (63-__builtin_clzll(tr[i][res]));
	    	}
	    	return res;
	    }
    
	    ll lower_bound(ll x) {
			if(siz==0 || max_element() < x) return -1LL;
	    	return lower_bound__(x,W-1,0);
	    }
    
	    ll lower_left_bound(ll x) {
			if(siz==0 || min_element() > x) return -1LL;
	    	return lower_left_bound__(x,W-1,0);
	    }
    
	    ll size() {
	    	return siz;
	    }
    
	    bool empty() {
	    	return siz==0;
	    }
    
	    void dump() {
	    	ll M = 1LL << B[W];
	    	M--;
	    	for(int i = 0; i <= M; i++) {
	    		if(count(i)) cout << i << " ";
	    	}
	    	cout << endl;
	    }
    
	/*
	    fastset(W) 
		@brief 非負整数を管理する64分木
		W = 3  [0, 262'143]        3MB 1ms  
		W = 4  [0, 16'777'215]     5MB 2ms
		W = 5  [0, 1'073'741'823]  136MB 60ms

		insert(x) xを挿入する。存在するならなにもしない。 O(W)
		erase(x) xを削除。存在しない時なにもしない。 O(W)
		count(x) xが存在するか。O(W)
		min_element()/max_element() 最小・最大要素。要素数0ならassert。 O(W)
		lower_bound(x) x以上最小。存在しないなら-1 O(W)
		lower_left_bound(x) x以下最大。存在しないなら-1. O(W)
		size(), empty() ... O(1)
	
	*/
};
