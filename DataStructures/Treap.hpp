class xorshift {
    uint64_t x;
    public:
        xorshift() {
            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
            x = rnd();
            for (int i = 0; i < 100; i++) {
                random();
            }
        }
        uint64_t random() {
            x = x ^ (x << 7);
            return x = x ^ (x >> 9);
    }
};


template<typename T1, typename T2>
struct Treap {
    xorshift rnd;
    public:
        Treap(function<T1(T1, T2, long long)> _fx) : fx(_fx) {}
    private:
        struct node_t{
            node_t* lch;
            node_t* rch;
            int pri, cnt;
            T1 val, acc;
            T2 lazy;
            bool rev;
 
            node_t(T1 v, int p) : val(v), pri(p), acc(v) , lch(nullptr), rch(nullptr), rev(false), cnt(1) {
                lazy = T2::ide();
            }
        };

        function<T1(T1, T2, long long)> fx;

 
        node_t* root = nullptr;

        long long count(node_t* t) {return !t ? 0 : t -> cnt;}
        
        T1 acc(node_t* t) {return !t ? T1::ide() : t -> acc; }

        

        node_t* pushup(node_t* t) {
            if(t) {
                t -> cnt = count(t -> lch) + count(t -> rch) + 1;
                t -> acc = op(op(acc(t -> lch), t -> val),  acc(t -> rch));
            }
            return t;
        }
 
 
        void pushdown(node_t *t) {
            if(t && t -> rev) {
                swap(t -> lch, t -> rch);
                if(t -> lch) t -> lch -> rev ^= 1;
                if(t -> rch) t -> rch -> rev ^= 1;
                t -> rev = false;
            }

            if(t && t -> lazy != T2::ide()) {
                if(t -> lch) {
                    t -> lch-> lazy = op(t -> lch -> lazy, t -> lazy);
                    t -> lch -> acc = fx(t -> lch -> acc, t -> lazy, count(t -> lch));
                }

                if(t -> rch) {
                    t -> rch -> lazy = op(t -> rch -> lazy, t -> lazy);
                    t -> rch -> acc = fx(t -> rch -> acc, t -> lazy, count(t -> rch));
                }

                t -> val = fx(t -> val, t -> lazy, 1LL);
                t -> lazy = T2::ide();
            }
            pushup(t);
        }
 
 
            
        
 
        
 
        void merge(node_t*& t, node_t* l, node_t* r) {
            pushdown(l), pushdown(r);
            if(!l || !r) t =  !l ? r : l;
            else if(l -> pri > r -> pri) {
                merge(l -> rch, l -> rch, r);
                t = l;
            } else {
               merge(r -> lch, l,r -> lch);
               t = r;
            }
            pushup(t);
        }


 
        void split(node_t* t, int k, node_t*& tl, node_t*& tr) {// [0, k) [k, n)
            if(!t) {
                tl = nullptr, tr = nullptr;
                return;
            }
            pushdown(t);
 
            if(k <= count(t -> lch)) {
                split(t -> lch, k, tl, t -> lch);
                tr = t;
            }else {
                split(t -> rch, k - count(t -> lch) - 1, t -> rch, tr);
                tl = t;
            }
            pushup(t);
        }


        //k+1個目、つまりk番目になる。
        void insert__(node_t*& t, int k,  node_t* item) {
            node_t* tl; node_t* tr;
            split(t, k, tl, tr);
            merge(tl, tl, item);
            merge(t, tl, tr);
        }
        
        void erase__(node_t*& t, int k) {
            node_t* tl; node_t* tm; node_t* tr;
            split(t, k+1, tl, tm);
            split(tl, k, tl, tr);
            merge(t, tl, tm);
        }
 
        void reverse__(node_t* t, int l, int r) {//[l, r)
            if(l >= r) return;
            node_t* tl; node_t* tm; node_t* tr;
            split(t, l, tl, tm);
            split(tm, r - l, tm, tr);
            tm -> rev ^= 1;
            merge(tm, tm, tr);
            merge(t, tl, tm);
        }
        
        void change__(node_t* t, int l, int r, T2 x) {
            if(l >= r) return;
            node_t* tl; node_t* tm; node_t* tr;
            split(t, l, tl, tm);
            split(tm, r - l, tm, tr);
            tm -> lazy = op(tm -> lazy, x);
            tm -> acc = fx(tm -> acc, x, count(tm));
            merge(tm, tm, tr);
            merge(t, tl, tm);

        }

        T1 query(int l, int r) {
            if(l >= r) return T1::ide();
            node_t* tl; node_t* tm; node_t* tr;
            split(root, l, tl, tm);
            split(tm, r-l, tm, tr);
            T1 res = acc(tm);
            merge(tm, tm, tr);
            merge(root, tl, tm);
            return res;
        }




        void dump__(node_t* t) {
            if(!t) return;
            pushdown(t);
            dump__(t -> lch);
            cout << t -> val.a << " ";
            dump__(t -> rch);
        }


      

 

    public:
        void insert(int pos, T1 val) {
            insert__(root, pos, new node_t(val,rnd.random()));
        }
 
        void erase(int pos) {
            erase__(root, pos);
        }
 
 
        void reverse(int l, int r) {//[l, r]をreverse
            if(l > r) return;
            reverse__(root, l, r+1);
        }
 
        void rotate(int l, int m, int r) {//[l, r] を mが先頭に来る様にreverse
            r++;
            if(l > r) return;
            reverse__(root, l, r);
            reverse__(root, l, l + r - m);
            reverse__(root, l + r - m, r);
        }
        
        T1 ith (int pos) {
            return query(pos, pos+1);
        }

        T1 get(int l, int r) {return query(l, r + 1);}

        

        void change(int l,int r, T2 val) {
            change__(root, l, r+1, val);
        }

        void dump() {
            dump__(root);
            cout << endl;
        }
 
        
  
};



/*
@brief Treap
*/