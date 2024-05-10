template<typename T>
struct li_chao_tree {
    struct line {
        T a, b; // y = ax + b
        line (T _a, T _b) : a(_a), b(_b) {}
        bool operator==(const line &c) {return a == c.a && b == c.b;}
        bool operator!=(const line& c) {return !(a == *this);}
        T operator()(T x) const {return a * x + b;}
    };

    int siz = 1;
    vector<line> dat;
    vector<T> X;//クエリで聞かれるx座標 sorted && unique済み前提
    T M = numeric_limits<T>::max();

  
    li_chao_tree (vector<T> &xs) { 
        while(siz < xs.size()) siz <<= 1;
        dat.resize(siz<<1, line(0, M));
        X.resize(siz+1, int_max);
        X[0] = -int_max;
        for(int i = 1; i <= int(xs.size()); i++) X[i] = xs[i-1];
    }
  
    void add_line_query(line nw, long long l, long long r, int idx) {
        int m = (l + r)/2;
        if(dat[idx] == line(0, M)) {
            dat[idx] = nw;
            return ; 
        }    

        T lx = X[l], mx = X[m], rx = X[r-1];
        bool lef = (nw(lx) < dat[idx](lx));
        bool mid = (nw(mx) < dat[idx](mx));
        bool rig = (nw(rx) < dat[idx](rx));
  
        if(lef && rig) {
            dat[idx] = nw;
            return;
        }
        if(!lef && !rig) return;
        if(mid)swap(dat[idx], nw);
        if(lef != mid) add_line_query(nw, l, m, idx<<1);
        else add_line_query(nw, m, r, idx<<1|1);
        
    }
  
    T get_query(T id) {
        T x = X[id];
        id += siz-1;
        T res = numeric_limits<T>::max();
        while(id >= 1) {
            res = min(res, dat[id](x));
            id >>= 1;
        }
        return res;
    }
  
    void add_line(T a, T b) {
        line nw(a, b);
        add_line_query(nw, 1, siz + 1, 1);
     }

    T get(T x) {
        int id = lower_bound(X.begin(), X.end(), x) - X.begin();
        return get_query(id);
    }

};

/*
@brief : Li chao tree
*/