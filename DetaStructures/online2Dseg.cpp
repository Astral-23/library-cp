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
		    UnlimitedSegTree<X, W> seg(minpos, maxpos)  X...データ W...添字の型  O(1)
			@brief: 動的セグ木
		
		*/

};

template<typename X, typename W>
struct online2Dseg {

    W MIN_H, MAX_H, MIN_W, MAX_W;
    online2Dseg(W _MIN_H, W _MAX_H, W _MIN_W, W _MAX_W) :  MIN_H(_MIN_H), MAX_H(_MAX_H), MIN_W(_MIN_W), MAX_W(_MAX_W) {
		MAX_H++;  MAX_W++;
	}

    private:
        struct NODE {
            UnlimitedSegTree<X, W> subtree;
            NODE* lch;
			NODE* rch;
            
            NODE(W _MIN_W, W _MAX_W) {
              subtree = DynamicSegTree<X, W>(_MIN_W, _MAX_W-1);
              lch = nullptr;
              rch = nullptr;
            }
        };

        NODE* root = nullptr;

    
 
        void change__(NODE*& now, W& a, W& b, W& h, W& w,  X& val) {//木の構造が変化しないなら、構成し直す必要も無い（splay木等根が変わりうるやつは話が別）
            if(now == nullptr)  now = new NODE(MIN_W, MAX_W);
            now -> subtree.change(w, val);//hを含む区間を持つ部分木に値を登録。この時、x(w)座標を登録する。
            W mid = (a+b)>>1;
            if(b - a == 1) return;//葉まで登録したら終わり。
            if(h < mid) change__(now -> lch, a, mid, h, w, val);
            else change__(now -> rch, mid, b, h, w, val);
        }

        
        X get__(NODE*& now, W& a, W& b, W& sy, W& ty, W& sx, W& tx) {// [sy, ty) × [sx, tx) := クエリ区間  [a, b) := 今見ているy(h)座標の区間   y = [sy, ty)での結果を返す。
            if(b <= sy || ty <= a) return X::ide();//範囲外なら単位元
            if(now == nullptr) return X::ide();//範囲内について、データが存在しないなら単位元//(これより子は、今より区間が狭い子しか存在し得ないから打ち切って良い。（仮想上の完全ニ分岐を想像すると早い)
            if(sy <= a && b <= ty) return now -> subtree.get(sx, tx-1);//w2は半開区間。yが完全に含まれる時。
            W mid = (a+b)>>1;
            X L = get__(now -> lch, a, mid, sy, ty, sx, tx);
            X R = get__(now -> rch, mid, b, sy, ty, sx, tx);
            return op(L, R);
        }


    public:
        void change(W y, W x, X val) {
           change__(root, MIN_H, MAX_H, y, x, val);
        }

        X  get(W sy, W ty, W sx, W tx) {
			ty++; tx++;
            return get__(root, MIN_H, MAX_H, sy, ty, sx, tx);
        }

        
};

struct Monoid {
    long long a;
    
    Monoid(){}
    Monoid(long long _a) : a(_a){};

    friend Monoid op(const Monoid& l, const Monoid& r) {
        Monoid res;
        res.a = l.a + r.a;
        return res;
    } 
    friend Monoid update(const Monoid& l, const Monoid& x) {
        Monoid res = l;
        res.a += x.a;
        return res;
    }

	static Monoid ide() {
		return 0;
	}
};

/*
@brief : 動的2次元セグ木
*/