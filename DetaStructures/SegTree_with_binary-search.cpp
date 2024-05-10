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

		template<class F> 
		int min_right__(int L, F f) {//初めてtrueになるインデックス。但し、どんなに右端を伸ばしてもtrueにならないなら-1
		    if(!f(get(L, n))) return -1;

			int l = L + n - 1;
			T res = T::ide();
			while(true) {
				if(l&1) {
					if(f(op(res, dat[l]))) break;
					else res = op(res, dat[l++]);
				}
				l >>= 1;
			}

			while(l < n) {//左を足してtrueなら左。そうじゃないなら右。
			    if(f(op(res, dat[l<<1]))) {
					l <<= 1;
				}
				else {
					res = op(res, dat[l<<1]);
					l = l << 1 | 1;
				}
			}
			//indexを返す。
			//今いるindexがそうである。
			return l - (n-1);
		}

		template<class F>
		int max_left__(int R, F f) {//初めてtrueになるインデックス。どこまで伸ばしてもfalseなら-1
		    if(!f(get(1, R))) return -1;

			int r = R + n - 1;
			T res = T::ide();

			while(true) {
				if(r&1) {
					if(f(op(dat[r-1], res))) break;
			        else res = op(dat[--r], res);
				}
				r >>= 1;
			}

			while(r > 1) {
				if(f(op(dat[r<<1|1], res))) {
					r = r<<1|1;
				}
				else {
					res = op(dat[r<<1|1], res);
					r <<= 1;
				}
			}

			return r - (n-1);
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

		template<class F>
		int min_right(int L, F f) {
			return min_right__(L, f);
		}

		template<class F>
		int max_left(int R, F f) {
			return max_left__(R, f);
		}
         
};



struct Monoid {
    long long a;
   
    Monoid(){}
      
    Monoid(long long _a) : a(_a) {
      
    }

    friend Monoid op(const Monoid& l, const Monoid& r) {
      }

    friend Monoid update(const Monoid& l, const Monoid& r) {

    }

    static Monoid ide() {
       return 0LL;
    }
    
};

int kth_pos;
int kth_element (const Monoid& now) {
	return now.a >= kth_pos;
};


int get_order(const Monoid& now, SegTree<Monoid>& seg) {
	return seg.get(1, now.a).a;
}

/*
@brief セグ木 + 二分探索
*/