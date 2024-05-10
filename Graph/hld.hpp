template<typename T>
struct SegTree {
    int n;
    vector<T> dat;
   
    SegTree(){}
         
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
            for(int i = n-1; i >= 1; i--)  dat[i] = op(dat[i<<1], dat[(i<<1) + 1]);
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



template <typename X>
struct HLD {
    vector<int> siz;
    vector<int> in;
	vector<int> rev;
    vector<int> out;
    vector<int> par;
    vector<int> head;
    SegTree<X> seg;
    int N;
    int size = 1;
	int root;
    
  
    HLD(vector<vector<int>>& G, int _root) : root(_root) {
		N = int(G.size()) - 1;
        par.resize(N+1);
        iota(par.begin(), par.end(), 0);
        siz.resize(N+1, 1);
        in.assign(N+1, -1);
        rev.resize(N+1, -1);
        out.resize(N+1, -1);
        head.resize(N+1);
        seg = SegTree<X>(N);
    
        auto dfs_siz = [&](auto f, int now, int prev) -> void {
            int sum = 1;
            for(int to : G[now]) {
                if(to == prev) continue;
                f(f, to, now);
                sum += siz[to];
            }
            siz[now] = sum;
            return;
        };
        dfs_siz(dfs_siz, root, -1);
        for(int i = 0; i <= N; i++) {
          sort(G[i].begin(), G[i].end(), [&](int a, int b) {
            return siz[a] > siz[b];
          });
        }
    
        int idx = 1;
        auto dfs_bunkai = [&](auto f, int now, int prev, int hed) -> void {
            in[now] = idx;//番号付
            rev[idx] = now;
            idx++;
            par[now] = prev;//親の頂点   //1だけは直前も自分も1
            if(hed == -1)hed = now;
            head[now] = hed;
      
            bool flag = true;
            
            for(int i = 0; i <= int(G[now].size()) - 1; i++) {
                if(in[G[now][i]] != -1) continue;
                if(flag) f(f, G[now][i], now, hed), flag = false;
                else f(f, G[now][i], now, -1);
            }
            out[now] = idx;
            return;
        };
        dfs_bunkai(dfs_bunkai, root, root, -1);
    }


    private:

	   

        X get__(int u, int v) {
            int w = getLCA(u, v);//lcaで左右に分ける
            X L = X::ide(), R = X::ide();
            while(u != w) {
                int hed = max<int>(in[head[u]], in[w]+1);//wまで登ると、wを左右で2回カウントしてしまう。
                L = op(seg.get(hed, in[u]), L); //根から上の方へ
                u = par[rev[hed]];
            }   
            L = op(seg.get(in[w], in[w]),  L);//根から上の方へ
            while(v != w) {
                int hed = max<int>(in[head[v]], in[w]+1);
                R = op(seg.get(hed, in[v]), R); //根から上の方へ
                v = par[rev[hed]];
            }
            return op(L, R);//交換則を要する時はこの行を変更する必要があるかもしれない : 無いと思うがr
        }
    
    public:

        void set(int pos, X x) {
            seg.set(in[pos], x);
        }

        void init() {
            seg.init();
        }

        void change(int pos, X x) {
            seg.change(in[pos], x);
        }

        X get(int u, int v) {
            return get__(u, v);
        }

        X subtree(int v) {
            return seg.get(in[v],  out[v]-1);
        }
  
        int getLCA(int a, int b) {
            while(true) {
                if(in[a] > in[b]) swap(a, b);
                if(head[a] == head[b]) return a;
                b = par[head[b]];
            }
        }
      
        int parent(int a) {
            return par[a];
        }

		void dump() {
			for(int i = 1; i <= N; i++) {
				cout << seg.get(in[i], in[i]).a << " ";
			}
			cout << endl;
		}

        /*
        HLD<Monoid> hld(G, root)  空間 O(N)
		@brief HLD(非可換)
		get(u, v) ... path(u, v)の頂点のモノイド積  O(log^2)
		change(v) ... vを変更 O(log)
		subtree(v) ... vを含む、vの部分木のモノイド積 O(log)
        
        
        outは半開区間。
        
        */
};  

