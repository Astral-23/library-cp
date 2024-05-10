template<typename X, typename W>
struct DynamicSegTree {// max_pos < LLONG_MAX(開区間の弊害)
    

    W  min_pos;
    W  max_pos;//渡す時は閉区間だが、開区間で扱う。
    DynamicSegTree(){} 
    DynamicSegTree(W _min_pos, W _max_pos) :  min_pos(_min_pos), max_pos(_max_pos) {
        assert(min_pos <= max_pos);//適切な区間が指定されているか
        assert(max_pos < LLONG_MAX);
		max_pos++;

    };


    private:
        struct Node {
            W pos;
            X val;
            X prod;
            Node* lch;
			Node* rch;
        
            Node(W p, X v, X pro) : pos(p), val(v), prod(pro) {
                lch = nullptr;
				rch = nullptr;
            }
        };
        
        Node* root = nullptr;

 
       
        X value(Node* now) {
            return now!=nullptr ? now -> prod : X::ide(); 
        }

        Node* change__(Node* now, W& a, W& b, W& p, X& x) {
            if(now == nullptr) {
                now = new Node(p, x, x);
                return now;
            }
            if(now -> pos == p) {
                now -> val = update(now -> val, x);
                now -> prod = op(value(now -> lch), op(now -> val, value(now -> rch)));//区間を管理するノードの答えを返す(左子・このノードに入ってる分(常に1ノード分）・右子)
                return now;
            }
            
            W mid = (a+b)>>1;
            if(p < mid) {
                if(now -> pos < p) swap(p, now -> pos), swap(x, now -> val);//子の方が順序が左になるように
                now -> lch = change__(now -> lch, a, mid, p, x);
            }
            else {
                if(now -> pos > p) swap(p, now -> pos), swap(x, now -> val);//子の方が順序が右になるように
                now -> rch = change__(now -> rch, mid, b, p, x);
            }
            now -> prod = op(value(now -> lch), op(now -> val, value(now -> rch)));
            return now;
        }

        X get__(Node* now, W& a, W& b, W l, W r) {// [l, r) := クエリ区間  [a, b) := 今見ている区間   [a, b]での結果を返す。
            if(b <= l || r <= a) return X::ide();//範囲外なら単位元
            if(now == nullptr) return X::ide();//範囲内について、データが存在しないなら単位元
            if(l <= a && b <= r) return now -> prod;//完全に含まれているなら返す。
            W mid = (a+b)>>1;
            X res = get__(now -> lch, a, mid, l, r);
            if(l <= now -> pos && now -> pos < r) res = op(res, now -> val);//[a , b)の値の居場所 : 今見ているノードが持っている値の添え字をidとして [a, id)を左の子が、idをこれが、(id, b)を右の子が持っている。
            return op(res, get__(now -> rch, mid, b, l, r));//今見ているノードが持つ範囲の分が計算し終わったので、返す。

        }



    public:
        void change(W pos, X x) {
           root = change__(root, min_pos, max_pos, pos, x);
        }

        X  get(W l, W r) {
            return get__(root, min_pos, max_pos, l, r+1);
        }

		/*
		    DynamicSegTree<X, W> seg(minpos, maxpos)  X...データ W...添字の型  O(1)
			@brief 動的セグ木
		
		*/

};

