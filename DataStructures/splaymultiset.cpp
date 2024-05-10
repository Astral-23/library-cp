template<typename X>
struct splay_multiset {
    struct node_t {
            X val;
            X acc;
            int sum = 0;
            node_t* lch;
            node_t* rch;
            node_t(X v):  val(v), acc(v) {
                sum = 1;
                lch = nullptr;
                rch = nullptr;
            }
    };
    using NODE = node_t;
    NODE* root = nullptr;//Splay木の根を表すノード。
    long long size_of_tree = 0;//木に登録されている要素数を返す。
    int pre = 0;
    splay_multiset(){}

    private:

        long long count(NODE* now) {return now == nullptr ? 0 : now -> sum;}
        X acc(NODE* now) {return !now ? X() : now -> acc;}

        NODE* pushup(NODE* now) {
            if(now != nullptr) {
                now -> sum = count(now -> lch) + count(now -> rch) + 1;
                now -> acc = acc(now -> lch) + now -> val + acc(now -> rch);
            }
            return now;
        }


        NODE* rotate(NODE* now, int b) {//ノードnowを回転させる処理。b = 1で右回転、 b = 0で左回転。」
            if(b==1) {
                NODE* s = now -> lch;
                now -> lch = s -> rch;
                s -> rch = now;
                pushup(now), pushup(s);
                return s;//戻り値は、回転した後nowの位置にくるノードのポインタ。
            }
            else {
                NODE* s = now -> rch;
                now -> rch = s -> lch;
                s -> lch = now;
                pushup(now), pushup(s);
                return s;
            }
        }

        NODE* splay_sub_pos(NODE* now, int pos, pair<int, NODE*>& history, bool& found) {
            if(now == nullptr) {
                found = false;
                return now;
            } 
            if(count(now -> lch) + 1 == pos) {
                return now;
            }

            int b = 1;
            if(count(now -> lch) + 1 < pos) {
                pos -= count(now -> lch) + 1;
                now -> rch = splay_sub_pos(now -> rch, pos, history, found);
                pushup(now);
            }
            else {
                b = 0, now -> lch = splay_sub_pos(now -> lch, pos, history, found);
                pushup(now);
            } 

            if(!found) return now;

            auto [pb, pn] = history;
            if(pn == nullptr) history = make_pair(b, now);
            else {
                history = make_pair(-1, nullptr);
                if(b == pb) {
                    now = rotate(now, 1 - b);
                    now = rotate(now, 1 - b);
                }
                else {
                    if(b==1) now -> rch = rotate(pn, 1 - pb);
                    else now -> lch = rotate(pn, 1 - pb);
                    pushup(now);
                    now = rotate(now, 1 - b);
                }
            }
            return now;
        }

        NODE* splay_sub(NODE* now, const X& x, pair<int, NODE*>& history, bool& found) {
            if(now == nullptr) {
                found = false;
                return now;
            } 
            if(now -> val == x) {
                return now;
            }

            int b = 1;
            if(x > now -> val) {
                now -> rch = splay_sub(now -> rch, x, history, found);
                pushup(now);
            }
            else if(x < now -> val) {
                b = 0, now -> lch = splay_sub(now -> lch, x, history, found);
                pushup(now);
            } 

            if(!found) return now;

            auto [pb, pn] = history;
            if(pn == nullptr) history = make_pair(b, now);
            else {
                history = make_pair(-1, nullptr);
                if(b == pb) {
                    now = rotate(now, 1 - b);
                    now = rotate(now, 1 - b);
                }
                else {
                    if(b==1) now -> rch = rotate(pn, 1 - pb);
                    else now -> lch = rotate(pn, 1 - pb);
                    pushup(now);
                    now = rotate(now, 1 - b);
                }
            }
            return now;
        }

        void splay(NODE* now, const X& x) {
            bool found = true;
            pair<int, NODE*> h(-1, nullptr);
            root = splay_sub(now, x, h, found);
            if(found && h.second != nullptr) {
                root = rotate(root, 1 - h.first);
            }
            return ;
        }

        void splay_pos(NODE* now, int pos) {
            bool found = true;
            pair<int, NODE*> h(-1, nullptr);
            root = splay_sub_pos(now, pos, h, found);
            if(found && h.second != nullptr) {
                root = rotate(root, 1 - h.first);
            }
            return ;

        }
 
 
        NODE* change__(NODE* now, X& x, int& pos) {//現在見ているノード | 挿入する値
            if(now == nullptr) {
                size_of_tree++;
                pos++;
                return new NODE(x);
            }
            if(x > now -> val) {
                pos += count(now -> lch);
                now -> rch = change__(now -> rch, x, pos);
                pushup(now);
                return now;
            }
            else if(x < now -> val) {
                now -> lch = change__(now -> lch, x, pos);
                pushup(now);
                return now;
            }
            else {
                pre ^= 1;
                if(pre) {
                    pos += count(now -> lch);
                    now -> rch = change__(now -> rch, x, pos);
                    pushup(now);
                    return now;
                }
                else {
                    now -> lch = change__(now -> lch, x, pos);
                    pushup(now);
                    return now;

                }
            }
        }

       
        NODE* find_max_only(NODE* now) {//nowを根とする部分木の中で最大の要素を持つノードを返す。この時、splay操作は行わない。
           if(now == nullptr) return now;
           NODE* res = now;
           while(res -> rch != nullptr) res  = res -> rch;
           return res;
        }

        NODE* find_min_only(NODE* now) {//nowを根とする部分木の中で最小の要素を持つノードを返す。この時、splay操作は行わない。
           if(now == nullptr) return now;
           NODE* res = now;
           while(res -> lch != nullptr) res = res -> lch;
           return res;
        }


        NODE* erase__(NODE*now, X& x){//削除ノードまで降っていき、削除が完了次第葉の方から再構成する。
            if(now == nullptr) return now;
            if(x < now -> val) {
                now -> lch = erase__(now -> lch, x);
                pushup(now);
            }
            else if(x > now -> val) {
                now -> rch = erase__(now -> rch, x);
                pushup(now);
            }
            else {
                if(now -> lch == nullptr) {//左に子がない時
                    NODE* tmp = now -> rch;
                    delete now;
                    size_of_tree--;
                    return tmp;
                }
                else if(now -> rch == nullptr) {//右に子がない時
                    NODE* tmp = now -> lch;
                    delete now;
                    size_of_tree--;
                    return tmp;
                } else {//右にも左にも子がある時
                    NODE* tmp = find_max_only(now -> lch);//左子孫の最大値
                    now -> val = tmp -> val;
                    now -> lch = erase__(now -> lch, tmp -> val);//移動したノードを削除。(ポインタの操作に注意)
                    pushup(now);
                }
            }
            return now;//現在のノードまで削除の作業が完了したらば、更新された現在のノードを返して終了。
        }


        int count__(NODE* now, X& x) {
            if(now == nullptr) return 0;
            if(now -> val == x) {
                return 1 + count__(now -> rch, x) + count__(now -> lch, x);
            }
            else if(now -> val > x) return count__(now -> lch, x);
            else return count__(now -> rch, x);
        }

        void lower_bound_val__(NODE*now, X& x, X& res) {//x以上で最小val
        //前提：その様な値が存在する。
            if(now -> val == x) {
                res = x;
                return;
            }
            if(x < now -> val) {//答えは、min(now, nowの左子孫の中でx以上の最小の要素)
                res = min(res, now -> val);
                if(now -> lch != nullptr) lower_bound_val__(now -> lch, x, res);
            }
            else {//答えは、右子孫の中でx以上の最小の値
                if(now -> rch != nullptr)  lower_bound_val__(now -> rch, x, res);//右に子が存在しないという事はない。
            }
            return;
        }

        void upper_bound_val__(NODE*now, X& x, X& res) {//x超過で最小val
        //前提：その様な値が存在する。
            if(x < now -> val) {//答えは、min(now, nowの左子孫の中でxより大きい最小の要素)
                res = min(res, now -> val);
                if(now -> lch != nullptr) upper_bound_val__(now -> lch, x, res);
            }
            else {//答えは、右子孫の中でxより大きいの最小の値
                if(now -> rch != nullptr)  upper_bound_val__(now -> rch, x, res);//右に子が存在しないという事はない。
            }
            return;
        }
      
      
        void lower_left_bound_val__(NODE* now, X& x, X& res) {//x以下で最大val
        //前提：その様な値が存在する。
            if(now -> val == x) {
                res = x;
                return;
            }
            if(x < now -> val) {//左
                if(now -> lch != nullptr) lower_left_bound_val__(now -> lch, x, res);
            }
            else {
                res = max(res, now -> val);
                if(now -> rch != nullptr) lower_left_bound_val__(now -> rch, x, res);

            }
        }

        void upper_left_bound_val__(NODE* now, X& x, X& res) {//x未満で最大val
        //前提：その様な値が存在する。
            if(x <= now -> val) {//左
                if(now -> lch != nullptr) upper_left_bound_val__(now -> lch, x, res);
            }
            else {
                res = max(res, now -> key);
                if(now -> rch != nullptr) upper_left_bound_val__(now -> rch, x, res);
            }
        }

        NODE* lower_bound__(X x) {//x以上で最小、存在しないならnullptr
            if(size_of_tree==0) return nullptr;
            NODE* M = find_max_only(root);
            X t = M -> val;
            if(t < x) return nullptr;//x以上の値は存在しない。
            lower_bound_val__(root, x, t);
            splay(root, t);
            return root;
        }

        NODE* upper_bound__(X x) {//k超過で最小、存在しないならnullptr
            if(size_of_tree==0) return nullptr;
            NODE* M = find_max_only(root);
            X t = M -> val;
            if(t <= x) return nullptr;
            upper_bound_val__(root, x, t);
            splay(root, t);
            return root;
        }

        NODE* lower_left_bound__(X x) {//k以下で最大。
            if(size_of_tree==0) return nullptr;
            NODE* m = find_min_only(root);
            X t = m -> val;
            ;
            if(t > x) return nullptr;
            lower_left_bound_val__(root, x, t);
            splay(root, t);
            return root;
        }

        NODE* upper_left_bound__(X x) {//k未満で最大。
            if(size_of_tree==0) return nullptr;
            NODE* m = find_min_only(root);
            X t = m -> val;
            if(t >= x) return nullptr;
            upper_left_bound_val__(root, x, t);
            splay(root, t);
            return root;
        }

        NODE* ith_element__(NODE* now, long long i) {
            long long ls = count(now -> lch);
            if(ls + 1 <= i && i <= ls + 1) {
                return now;
            }
            else if(ls >= i) return ith_element__(now -> lch, i);
            else return ith_element__(now -> rch, i - 1 - ls);
        }

        NODE* max_element__() {//最大のkey、存在しないならnullptr
            NODE* tar = find_max_only(root);
            if(tar == nullptr) return tar;
            pair<int, NODE*> h (-1, nullptr);
            splay(root , tar -> val);
            return root;
        }

        NODE* min_element__() {//最小のkey、存在しないならnullptr
            NODE* tar = find_min_only(root);
            if(tar == nullptr) return tar;
            pair<int, NODE*> h (-1, nullptr);
            splay(root , tar -> val);
            return root;
        }

        NODE* lower_sum_left__(NODE* now, X S, int L) {
            X now_sum = X();
            if(L != 1) {
                S = S + accL(L-1);
            }
            int pos = 0;
            if(S > acc(root)) return nullptr;
            while(1) {
                X tmp = now_sum + acc(now -> lch);
                if(tmp >= S) now = now -> lch;
                else {
                    tmp += now -> val;
                    pos += 1 + count(now -> lch);
                    if(tmp >= S) {
                        splay_pos(root, pos);
                        return root;
                    }
                    else {
                        now_sum = tmp;
                        now = now -> rch;
                    }
                }
            }
        }

        NODE* upper_sum_left__(NODE* now, X S, int L) {
            X now_sum = X();
            if(L != 1) {
                S = S + accL(L-1);
            }
            int pos = 0;
            if(S >= acc(root)) return nullptr;
            while(1) {
                X tmp = now_sum + acc(now -> lch);
                if(tmp > S) now = now -> lch;
                else {
                    tmp += now -> val;
                    pos += 1 + count(now -> lch);
                    if(tmp > S) {
                        splay_pos(root, pos);
                        return root;
                    }
                    else {
                        now_sum = tmp;
                        now = now -> rch;
                    }
                }
            }
        }

        NODE* next(NODE*& now) {//次のkey、存在しないならnullptr
            if(now == nullptr) return now;
            else return upper_bound__(now -> val);
        }


        NODE* prev(NODE*& now) {//前のkey。存在しなければnullptr
            if(now == nullptr) return now;
            else return upper_left_bound__(now -> val);
        }

        void in_order__(NODE* now, vector<X>& res) {
            if(now == nullptr) return;
            in_order__(now -> lch, res);
            res.push_back(now -> val);
            in_order__(now -> rch, res);
            return;
        }
        
        void change(X x) {//xを挿入)
            pushup(root);
            int pos = 0;
            root = change__(root, x, pos);
            splay_pos(root, pos);//根を更新。
            return;
        }




    public:


        void insert(X x) {
            pushup(root);
            change(x);
        }

        void erase(X x) {//存在しなかった場合、何もしない。
            pushup(root);
            root = erase__(root, x);
        }

        bool find(X x) {
            pushup(root);
            splay(root,x);
            if(root == nullptr || root -> val != x) return false;
            return true;
        }

        int count(X x) {
            pushup(root);
            pair<int, NODE*> h (-1, nullptr);
            splay(root, x);
            if(root == nullptr || root -> val != x) return 0;
            return count__(root, x);
        }


        
        
  
        int size() {
            return size_of_tree;
        }

        bool empty() {
            return size_of_tree == 0;
        }

        
        bool next(X x, X& res) {//次のkey。存在しないならfalse。結果はresに渡される。
            pushup(root);
            NODE* r = upper_bound__(x);
            if(r==nullptr)return false;
            else {
                res = r -> val;
                return true;
            }
        }

        
        bool prev(X x, X& res) {//前のkey.存在しないならfalse。結果はresに渡される。
            pushup(root);
            NODE* r = upper_left_bound__(x);
            if(r==nullptr)return false;
            else {
                res = r -> val;
                return true;
            }
        }

        bool ith_element(long long i, X& res) {
            pushup(root);
            if(count(root) < i) return false;
            else {
                NODE* tar = ith_element__(root, i);
                res = tar -> val;
                return i;
            }
        }

        bool max_element(X& res) {//最大のkey
            pushup(root);
            NODE* tar = max_element__();
            if(tar == nullptr) return false;
            else {
                res =  tar -> val;
                return true;
            }
        }

        bool min_element(X& res) {//最小のkey
            pushup(root);
            NODE* tar = min_element__();
            if(tar == nullptr) return false;
            else {
                res =  tar -> val;
                return true;
            }
        }

        bool lower_bound(X x, X& res) {//x以上で最小key
            pushup(root);
            NODE* r = lower_bound__(x);
            if(r == nullptr) return false;
            else {
                res = r -> val;
                return true;
            }
        }

        bool upper_bound(X x, X& res) {//k超過で最小となる
            pushup(root);
            NODE* r = upper_bound__(x);
            if(r == nullptr) return false;
            else {
                res = r -> val;
                return true;
            }
        }

        bool lower_left_bound(X x, X& res) {//k以下で最大。 
            pushup(root);
            NODE* r = lower_left_bound__(x);
            if(r == nullptr) return false;
            else {
                res = r -> val;
                return true;
            }
        }

        bool upper_left_bound(X x, X& res) {//k未満で最大。
            pushup(root);
            NODE* r = upper_left_bound__(x);
            if(r == nullptr) return false;
            else {
                res = r -> val;
                return true;
            }
        }

        X accL(int R) {//[1, R]のvalのモノイド積 Rがkeyの数より多いと単位元
            if(R < 1 || size_of_tree < R) return X();
            pushup(root);
            X tar;
            if(!ith_element(R, tar)) return X();
            splay(root, tar);
            return acc(root -> lch) + root -> val;
        }

        X accR(int L) {//[L, MAX]のvalのモノイド
            if(L < 1 || size_of_tree < L) return X();
            pushup(root);
            X tar;
            if(!ith_element(L, tar)) return X();
            splay(root, tar);
            return root -> val + acc(root -> rch);
        }

        bool lower_sum_left(X sum, int L, X& res) {
            pushup(root);
            NODE* tar = lower_sum_left__(root, sum, L);
            if(tar == nullptr) return false;
            else {
                res = acc(tar -> lch) + tar -> val;
                return true;
            }

        }

        bool upper_sum_left(X sum, int L, X& res) {
            pushup(root);
            NODE* tar = upper_sum_left__(root, sum, L);
            if(tar == nullptr) return false;
            else {
                //res = acc(tar -> lch) + tar -> val;
                res = count(tar -> lch) + 1;
                return true;
            }

        }

        
        vector<X> in_order() {//要素を全て入れた配列 要素がないなら空配列
            pushup(root);
            vector<X> res;
            in_order__(root, res);
            return res;
        }

        void dump() {
            pushup(root);
            auto r = in_order();
            for(X& x : r) cout << x << " ";
            cout << endl;
        }

        NODE* end() {
            return nullptr;
        }

};

/*
@brief splaytree(multiset) トップダウンsplay
*/