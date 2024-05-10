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
    
        X search_kth(Node* k, int l, S remain) {
			X res = 0;
			while(1) {
                if(l == W) break;
				eval(k, l);
                if(k -> l && k -> l -> s >= remain) {
					k = k -> l;
				}
                else {
					if(k -> l) remain -= k -> l -> s;
					res += X(1) << (W - l - 1);
					k = k -> r;
                }
				l++;
			}
			return res;
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

        X search_maix(Node* k, int l, int type) {//type == 1がmax、type == 0がmin
		    X res = 0;
		    while(1) {
                eval(k, l);
                if(l == W) break;
                if(type == 1) {
					if(k -> r && k -> r -> s != 0) {
						res += X(1) << (W - l - 1);
						k = k -> r;
					}
					else k = k -> l;
					l++;
                }
                else {
                    if(k -> l && k -> l -> s != 0) {
						k = k -> l;
						l++;
					}
                    else {
						res += X(1) << (W - l - 1);
						k = k -> r;
						l++;
					} 
                }
			}
			return res;
        }
        
        
        S cnt_bound__(Node* k, int l, X& x) {//x以下の要素の総数
		    if(!k) return S();
            eval(k, l);
            if(l == W) return k -> s;
            if(x >> (W-l-1)&1) return upper_bound__(k -> r, l+1, x) + k -> l -> s;
            else return upper_bound_(k -> l, l+1, x);
        }
    
    
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
    
        X kth_element(S k) {//小さい方からk番目の値 要素数 < kの場合エラ-
            assert(root -> s >= k);
            return search_kth(root, 0, k);
        }
    
        void ope_xor(X x) {//収容されている要素全てにxをxor作用させる
            if(root -> s == 0) return;//要素が存在しない
            root -> lazy ^= x;
            eval(root, 0);
        }
        
		
        bool upper_bound(X x, X& res) {//xより大きい最小の要素
		    S pos = 1 + cnt_count__(root, 0, x);
			if(pos > size) return false;
			res = kth_element(pos);
			return true;
        }
    
        bool lower_bound(X x, X& res) {//x以上の最小の要素
		    if(x==0) {
				if(size()==0) return false;
				res = min_element();
				return true;
			}
            return upper_bound(x-1, res);
        }
    
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

			bool lower_bound(x, &res) ... x以上の要素が存在するならtrue, そのうち最小をresに代入  O(W)
			bool upper_bound(x, &res) ... O(W)

			空間: 挿入ごとにO(W)

		
		*/
};    
