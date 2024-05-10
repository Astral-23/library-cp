template<typename K, typename X>
struct node_t {
        K key;
        X val;
        int sum = 0;
        node_t* lch;
        node_t* rch;
        node_t(K k, X v): key(k), val(v) {
            sum = 1;
            lch = nullptr;
            rch = nullptr;
        }
};


template<typename K, typename X>
struct splay_map {
    using NODE = node_t<K, X>;
    NODE* root = nullptr;//Splay木の根を表すノード。
    long long size_of_tree = 0;//木に登録されている要素数を返す。
    splay_map(){}

    private:

        long long count(NODE* now) {return now == nullptr ? 0 : now -> sum;}

        NODE* pushup(NODE* now) {
            if(now != nullptr) now -> sum = count(now -> lch) + count(now -> rch) + 1;
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

        NODE* splay_sub(NODE* now, const K& k, pair<int, NODE*>& history, bool& found) {
            if(now == nullptr) {
                found = false;
                return now;
            } 
            if(now -> key == k) {
                return now;
            }

            int b = 1;
            if(k > now -> key) {
                now -> rch = splay_sub(now -> rch, k, history, found);
                pushup(now);
            }
            else if(k < now -> key) {
                b = 0, now -> lch = splay_sub(now -> lch, k, history, found);
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

        void splay(NODE* now, const K& k) {
            bool found = true;
            pair<int, NODE*> h(-1, nullptr);
            root = splay_sub(now, k, h, found);
            if(found && h.second != nullptr) {
                root = rotate(root, 1 - h.first);
            }
            return ;
            
        }
 
 
        NODE* change__(NODE* now, K& k, X& x) {//現在見ているノード | 挿入する値
            if(now == nullptr) {
                size_of_tree++;
                return new NODE(k, x);
            }
            if(k == now -> key) {//もう値xが存在するならば
                now -> val = x;
                pushup(now);
                return now;
            }
            else {//存在しないならば
                if(k > now -> key) {
                    now -> rch = change__(now -> rch, k, x);
                    pushup(now);
                    return now;
                }
                else {
                    now -> lch = change__(now -> lch, k, x);
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


        NODE* erase__(NODE*now, K& k){//削除ノードまで降っていき、削除が完了次第葉の方から再構成する。
            if(now == nullptr) return now;
            if(k < now -> key) {
                now -> lch = erase__(now -> lch, k);
                pushup(now);
            }
            else if(k > now -> key) {
                now -> rch = erase__(now -> rch, k);
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
                    now -> key = tmp -> key;
                    now -> lch = erase__(now -> lch, tmp -> key);//移動したノードを削除。(ポインタの操作に注意)
                    pushup(now);
                }
            }
            return now;//現在のノードまで削除の作業が完了したらば、更新された現在のノードを返して終了。
        }

        void lower_bound_val__(NODE*now, K& k, K& res) {//k以上で最小key
        //前提：その様な値が存在する。
            if(now -> key == k) {
                res = k;
                return;
            }
            if(k < now -> key) {//答えは、min(now, nowの左子孫の中でx以上の最小の要素)
                res = min(res, now -> key);
                if(now -> lch != nullptr) lower_bound_val__(now -> lch, k, res);
            }
            else {//答えは、右子孫の中でx以上の最小の値
                if(now -> rch != nullptr)  lower_bound_val__(now -> rch, k, res);//右に子が存在しないという事はない。
            }
            return;
        }

        void upper_bound_val__(NODE*now, K& k, K& res) {//k超過で最小key
        //前提：その様な値が存在する。
            if(k < now -> key) {//答えは、min(now, nowの左子孫の中でxより大きい最小の要素)
                res = min(res, now -> key);
                if(now -> lch != nullptr) upper_bound_val__(now -> lch, k, res);
            }
            else {//答えは、右子孫の中でxより大きいの最小の値
                if(now -> rch != nullptr)  upper_bound_val__(now -> rch, k, res);//右に子が存在しないという事はない。
            }
            return;
        }
      
      
        void lower_left_bound_val__(NODE* now, K& k, K& res) {//k以下で最大key
        //前提：その様な値が存在する。
            if(now -> key == k) {
                res = k;
                return;
            }
            if(k < now -> key) {//左
                if(now -> lch != nullptr) lower_left_bound_val__(now -> lch, k, res);
            }
            else {
                res = max(res, now -> key);
                if(now -> rch != nullptr) lower_left_bound_val__(now -> rch, k, res);

            }
        }

        void upper_left_bound_val__(NODE* now, K& k, K& res) {//k未満で最大key
        //前提：その様な値が存在する。
            if(k <= now -> key) {//左
                if(now -> lch != nullptr) upper_left_bound_val__(now -> lch, k, res);
            }
            else {
                res = max(res, now -> key);
                if(now -> rch != nullptr) upper_left_bound_val__(now -> rch, k, res);

            }
        }

        NODE* lower_bound__(K k) {//x以上で最小、存在しないならnullptr
            if(size_of_tree==0) return nullptr;
            NODE* M = find_max_only(root);
            K t = M -> key;
            if(t < k) return nullptr;//x以上の値は存在しない。
            lower_bound_val__(root, k, t);
            splay(root, t);
            return root;
        }

        NODE* upper_bound__(K k) {//k超過で最小、存在しないならnullptr
            if(size_of_tree==0) return nullptr;
            NODE* M = find_max_only(root);
            K t = M -> key;
            if(t <= k) return nullptr;
            upper_bound_val__(root, k, t);
            splay(root, t);
            return root;
        }

        NODE* lower_left_bound__(K k) {//k以下で最大。
            if(size_of_tree==0) return nullptr;
            NODE* m = find_min_only(root);
            K t = m -> key;
            if(t > k) return nullptr;
            lower_left_bound_val__(root, k, t);
            splay(root, t);
            return root;
        }

        NODE* upper_left_bound__(K k) {//k未満で最大。
            if(size_of_tree==0) return nullptr;
            NODE* m = find_min_only(root);
            K t = m -> key;
            if(t >= k) return nullptr;
            upper_left_bound_val__(root, k, t);
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
            splay(root , tar -> key);
            return root;
        }

        NODE* min_element__() {//最小のkey、存在しないならnullptr
            NODE* tar = find_min_only(root);
            if(tar == nullptr) return tar;
            pair<int, NODE*> h (-1, nullptr);
            splay(root , tar -> key);
            return root;
        }

        NODE* next(NODE*& now) {//次のkey、存在しないならnullptr
            if(now == nullptr) return now;
            else return upper_bound__(now -> key);
        }


        NODE* prev(NODE*& now) {//前のkey。存在しなければnullptr
            if(now == nullptr) return now;
            else return upper_left_bound__(now -> key);
        }

        void in_order__(NODE* now, vector<pair<K, X>>& res) {
            if(now == nullptr) return;
            in_order__(now -> lch, res);
            res.push_back(make_pair(now -> key, now -> val));
            in_order__(now -> rch, res);
            return;
        }
        
        
        X get(K k) {
            pushup(root);
            splay(root, k);
            if(root != nullptr && root -> key == k) return root -> val;
            else {
                change(k, X());
                return root -> val;
            }
        }
        void change(K k, X x) {//xを挿入
            pushup(root);
            root = change__(root, k, x);
            splay(root, k);//根を更新。
            return;
        }

        void add(K k, X x) {// map[k] += x;
            pushup(root);
            change(k, get(k) + x);
            pushup(root);
        }




    public:

        const X& operator[](const K& k) const {
            pushup(root);
            splay(root, k);
            if(root != nullptr && root -> key == k) return root -> val;
            else {
                change(k, X());
                return root -> val;
            }
        }

        X& operator[](const K& k)  {
            pushup(root);
            splay(root, k);
            if(root != nullptr && root -> key == k) return root -> val;
            else {
                change(k, X());
                return root -> val;
            }
        }


        

        void erase(K k) {//存在しなかった場合、何もしない。
            pushup(root);
            root = erase__(root, k);
        }

        int count(K k) {
            pushup(root);
            pair<int, NODE*> h (-1, nullptr);
            splay(root, k);
            if(root == nullptr || root -> key != k) return 0;
            else return 1;
        }


        int size() {
            return size_of_tree;
        }

        bool empty() {
            return size_of_tree == 0;
        }

        
        bool next(K k, K& res) {//次のkey。存在しないならfalse。結果はresに渡される。
            pushup(root);
            NODE* r = upper_bound__(k);
            if(r==nullptr)return false;
            else {
                res = r -> key;
                return true;
            }
        }

        
        bool prev(K k, K& res) {//前のkey.存在しないならfalse。結果はresに渡される。
            pushup(root);
            NODE* r = upper_left_bound__(k);
            if(r==nullptr)return false;
            else {
                res = r -> key;
                return true;
            }
        }

        bool ith_element(long long i, K& res) {
            pushup(root);
            if(count(root) < i) return false;
            else {
                NODE* tar = ith_element__(root, i);
                res = tar -> key;
                return i;
            }
        }

        long long get_order(K& k) {
            pushup(root);
            splay(root, k);
            if(root == nullptr || root -> key != k) return -1LL;
            else return count(root -> lch) + 1;
        }

        bool max_element(K& res) {//最大のkey
            pushup(root);
            NODE* tar = max_element__();
            if(tar == nullptr) return false;
            else {
                res =  tar -> key;
                return true;
            }
        }

        bool min_element(K& res) {//最小のkey
            pushup(root);
            NODE* tar = min_element__();
            if(tar == nullptr) return false;
            else {
                res =  tar -> key;
                return true;
            }
        }

        pair<K, X> MAX() {
            pushup(root);
            NODE*tar = max_element__();
            if(tar == nullptr) return make_pair(K(), X());
            else {
                return make_pair(tar -> key, tar -> val);
            }
        }

        pair<K, X> MIN() {
            pushup(root);
            NODE*tar = min_element__();
            if(tar == nullptr) return make_pair(K(), X());
            else {
                return make_pair(tar -> key, tar -> val);
            }
        }


       


        bool lower_bound(K k, K& res) {//x以上で最小key
            pushup(root);
            NODE* r = lower_bound__(k);
            if(r == nullptr) return false;
            else {
                res = r -> key;
                return true;
            }
        }

        bool upper_bound(K k, K& res) {//k超過で最小、
            pushup(root);
            NODE* r = upper_bound__(k);
            if(r == nullptr) return false;
            else {
                res = r -> key;
                return true;
            }
        }

        bool lower_left_bound(K k, K& res) {//k以下で最大。 
            pushup(root);
            NODE* r = lower_left_bound__(k);
            if(r == nullptr) return false;
            else {
                res = r -> key;
                return true;
            }
        }

        bool upper_left_bound(K k, K& res) {//k未満で最大。
            pushup(root);
            NODE* r = upper_left_bound__(k);
            if(r == nullptr) return false;
            else {
                res = r -> key;
                return true;
            }
        }

        
        vector<pair<K, X>> in_order() {//要素を全て入れた配列 要素がないなら空配列
            pushup(root);
            vector<pair<K, X>> res;
            in_order__(root, res);
            return res;
        }

        void dump() {
            pushup(root);
            auto r = in_order();
            for(auto [k, x] : r) cout << "[" << k << ": " << x << "] ";
            cout << endl;
        }

        NODE* end() {
            return nullptr;
        }

};

/*
@brief splaytree(map) トップダウンsplay
*/