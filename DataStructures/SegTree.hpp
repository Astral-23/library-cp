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


/*
@brief セグメント木
@docs docs/segtree.md
*/