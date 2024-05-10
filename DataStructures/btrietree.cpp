template<typename X, typename S>
struct Binary_Trie {
    struct Node {
          Node* l = nullptr;
          Node* r = nullptr;
          S s = 0; 
          X lazy = 0;
          Node (){}
    };

    int W = 0;
	Binary_Trie(){}
    Binary_Trie(int _W) : W(_W){}

	
    Node* root = new Node;//Binary_Trie_Treeの根を表すノード。


    private:
        void eval(Node* k, int l) {
            X x = k -> lazy;//今のノードのlazy
            if(l != W && x != 0) {//葉でないなら
                if(k -> l)k -> l -> lazy ^= x;//伝播
                if(k -> r)k -> r -> lazy ^= x;//伝播
          
                if(x >> (W - l - 1) & 1) {
				    swap(k -> l, k -> r);//相当するbitが立っているならswap
			    }
			}
            k -> lazy = 0;
            return ;
        }    
    
        pair<X, S> search_kth(Node*& k, int l, S& remain) {
			if(!k) k = new Node;
            eval(k, l);
            if(l == W) return pair(X(0), k -> s);//葉なら即座に0を返す。
            if(k -> l && k -> l -> s >= remain) return search_kth(k -> l, l+1, remain);
            else {
                if(k -> l)remain -= k -> l -> s;
                auto f = search_kth(k -> r, l+1, remain);
                f.first += (X(1) << (W - l - 1));//上からl+1bit目⇔したからW - lbit目
                return f;
            }
        }
    
        void search_ie(Node*& k, int l, S t, X& x) {//insert/eraseの探索関数。tは関数を共通化する為のパラメータ。t >= 1ならinsert、t <= -1ならerase
		    if(!k) k = new Node;
            eval(k, l);
            k -> s += t;
            //assert(k -> s >= 0);
            if(l != W) {
                if(x >> (W - l - 1) & 1) search_ie(k -> r, l+1, t, x);//右に移動  //Wbit中、上からl + 1番目 ⇔ 下から W - l番目
                else search_ie(k -> l, l+1, t, x);//左に移動
			}
            return ;
        }

        S search_count(Node*& k, int l, X& x) {//countの為の探索関数
		    if(!k) k = new Node;
            eval(k, l);
            if(l == W) return k -> s;//葉に到達したならばそのsを返す。
            if(k -> s == 0) return S(0);//s = 0の頂点が存在したならば即座に0を返す。
            //evalによって既に子の存在は保証されている。
            if(x >> (W - l - 1) & 1) return search_count(k -> r, l+1, x);//右に移動
            else return search_count(k -> l, l+1, x);//左に移動
        }

        X search_maix(Node*& k, int l, int type) {//type == 1がmax、type == 0がmin
		    if(!k) k = new Node;
            eval(k, l);
            if(l == W) return X(0);//葉なら即座に0を返す。
            if(type == 1) {
                if(k -> r && k -> r -> s != 0) return (X(1) << (W - l - 1)) + search_maix(k -> r, l+1, type); //右に移動 //上からl+1bit目が1だとわかった ⇔ 下からW - lbit目が1
                else return search_maix(k -> l, l+1, type);//左に移動
            }
            else {
                if(k -> l && k -> l -> s != 0) return search_maix(k -> l, l+1, type);//左に移動  
                else return (X(1) << (W - l - 1)) + search_maix(k -> r, l+1, type);//右に移動
            }
        }
        
        /*
        S _bound__(Node* k, int l, X& x) {//x超過の要素の総数
            eval(k, l);
            if(l == W) return k -> s;
            if(x >> (W-l-1)&1) return upper_bound__(k -> r, l+1, x) + k -> l -> s;
            else return upper_bound_(k -> l, l+1, x);
        }*/
    
    
    public:
        void insert(X x, S cnt) {//値xをcnt個挿入
            search_ie(root, 0, cnt, x);
        }
    
        void erase(X x, S cnt) {//値xをcnt個削除(元の個数を超えた場合エラー)
            search_ie(root, 0,  cnt * -1, x);
        }
        
        S count(X x) {//値xの個数
            return search_count(root, 0, x);
        }
    
        X max_element() {//最大値 要素数 = 0の場合エラー
            assert(root -> s > 0);
            return search_maix(root, 0, 1);
        }
    
        X min_element() {//最小値 要素数 = 0の場合エラー
            assert(root -> s > 0);
            return search_maix(root, 0, 0);
        }
    
        pair<X, S> kth_element(S k) {//小さい方からk番目の値とその個数 要素数 < kの場合エラ-
            assert(root -> s >= k);
            return search_kth(root, 0, k);
        }
    
        void ope_xor(X x) {//収容されている要素全てにxをxor作用させる
            if(root -> s == 0) return;//要素が存在しない
            root -> lazy ^= x;
            eval(root, 0);
        }
        
		/*
        S upper_bound(X x) {//xより大きい最小の要素が何番目か
            return 1 + upper_bound_(root, 0, x);
        }
    
        S lower_bound(X x) {//x以上の最小の要素が何番目か
            if(x == 0) return size();
            else return upper_bound(x - 1);
        }*/
    
        S size() {//収容されている要素の総数
            return root -> s;
        }


		void dump() {
			S s = size();
			for(S i = 1; i <= s; i++) {
				cout << kth_element(i).first << " ";
			}
			cout << endl;
		}

		/*
		    Binary_Trie<X, S>(W)   X...登録する値・xorする値の型  S...値の個数の型  W...最大bit長   O(1)
			@brief: Binary_Trie
			insert(x, cnt = 1) ... O(W)
			erase(x, cnt = 1) ... O(W)
			count(x) ... O(W)
			mex_element()/min_element() ... O(W)
			pair<X, S> kth_element(k)  ... O(W) {値、個数}を返す
			ope_xor(x) ... 集合全体にxをxor作用 O(1)
			size() ... O(1)

			空間: 挿入ごとにO(W)

		
		*/
};    

template<typename T>
struct SegTree {
    int n;
    vector<Binary_Trie<T,int>> dat;

         
    SegTree(int siz, int W) {
        n = 1;
        while(n < siz) n <<= 1;
        //dat.resize(n * 2, Binary_Trie<T, int>(W));
		dat.resize(n*2);
		for(int i = 1; i < n * 2; i++) dat[i] = Binary_Trie<T, int>(W);
    }

    private:
         
        T query(int l, int r, T x) {
            T L = numeric_limits<T>::max();
			T R = numeric_limits<T>::max();
            l += n - 1, r += n - 1;
            while(l < r) {
                if(l & 1) {
					dat[l].ope_xor(x);
					L = min(L, dat[l].min_element());
					dat[l].ope_xor(x);
					l++;
				}
                if(r & 1) {
					r--;
					dat[r].ope_xor(x);
					R = min(dat[r].min_element(), R);
					dat[r].ope_xor(x);
				}
                l >>= 1, r >>= 1;
            }  
            return  min(L, R);
        }

    
    public:
        /*
        void set(int pos, T x) {
            pos += n-1;
            dat[pos] = x;
        }
          
        void init() {
            for(int i = n-1; i >= 1; i--)  dat[i] = op(dat[i<<1], dat[(i<<1) + 1]);
        }*/
          
        void add(int pos, T x, int cnt) {
            pos += n - 1;
            dat[pos].insert(x, cnt);
            while(pos >= 2) {
                pos >>= 1;
				dat[pos].insert(x, cnt);
            }
        }


        T get(int l, int r, T x) {// [l, r]の演算結果。
            return query(l, r+1, x);
        }

        T operator[](int pos) {
            return dat[pos + n - 1];
        }
         
};

/*
@brief range xor range min
*/