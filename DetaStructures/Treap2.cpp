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

template<typename T>
struct Treap {
    xorshift rnd;

    private:
        struct node_t{
            node_t* lch;
            node_t* rch;
            int pri = 0, cnt = 1;
            T val;
            bool rev;

            node_t(){}
            node_t(T v, int p) : val(v), pri(p) {
                lch = rch = nullptr;
                rev = false;
            }
        };

        node_t* root = nullptr;

            
        int count(node_t* t) {return !t ? 0 : t -> cnt;}
        

        node_t* pushup(node_t* t) {
           if(t) t -> cnt = count(t -> lch) + count(t -> rch) + 1;
            return t;
        }

        void pushdown(node_t *t) {
            if(t && t -> rev) {
                swap(t -> lch, t -> rch);
                if(t -> lch) t -> lch -> rev ^= 1;
                if(t -> rch) t -> rch -> rev ^= 1;
                t -> rev = false;
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

        node_t* ith__(node_t* t, int k) {
            pushdown(t);
            int c = count(t -> lch), b = (k > c);
            if(k == c) return t;
            if(b) return ith__(t -> rch, k - (c+1));
            else return ith__(t -> lch, k);
        }


        void dump__(node_t* t) {
            if(!t) return;
            pushdown(t);
            dump__(t -> lch);
            cout << t -> val << " ";
            dump__(t -> rch);
        }




    

    public:
        void insert(int pos, T val) {
            insert__(root, pos, new node_t(val,rnd.random()));
        }

        void erase(int pos) {
             erase__(root, pos);
        }


        void reverse(int l, int r) {
            reverse__(root, l, r+1);
        }
        
        T ith(int pos) {
            return ith__(root, pos) -> val;
        }

        int size() {
            return count(root);
        }

        void dump() {
            dump__(root);
            cout << endl;
        }

};

/*
@brief Treap(値集約なし)
*/

