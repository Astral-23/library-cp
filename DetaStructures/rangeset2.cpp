template<typename T>
struct rangeset {//区間を管理する。ついでで、mexを取得できる。
    set<pair<T, T>> s;
    long long sum; //区間長の合計。

    rangeset() {
        T M = numeric_limits<T>::max();
        T m = numeric_limits<T>::min();
        s.emplace(m, m);
        s.emplace(M, M);
        sum = 0;
    }

    private:
        void insert__(T x) {
            auto nitr = s.lower_bound(make_pair(x+1, x+1));
            auto itr = prev(nitr);
            auto[nl, nr] = *nitr;
            auto[l, r] = *itr;
            if(l <= x && x <= r) return;//既に存在した。
            sum++;//合計に足しとく。
            if(r == x-1) {
                if(nl == x+1) {
                    s.erase(itr);
                    s.erase(nitr);
                    s.emplace(l, nr);
                } 
                else {
                    s.erase(itr);
                    s.emplace(l, r+1);
                }
            }
            else {
                if(nl == x+1) {
                    s.erase(nitr);
                    s.emplace(nl-1, nr);
                }
                else {
                    s.emplace(x, x);
                }
            }
            return;
        }

        void insert__(T L, T R) {
            //合計は、最後に[L, R]分足す事にして、道中は引く。
            if(L > R) return;
            auto itr = prev(s.lower_bound(make_pair(L+1, L+1)));

            {//まず、左端を処理。
                auto [l, r] = *itr;
                if(l <= L && R <= r) {//新たな区間が内包される。
                    return;
                }
                else if(l == L && r <= R) {//新たな区間が内包する。
                    s.erase(itr++);//融合
                    sum -= (r - l) + 1;
                }
                else if(l < L && L <= r && r < R) {//重なる部分がある。
                    L = l;
                    s.erase(itr++);//融合
                    sum -= (r - l) + 1;
                }
                else {//重なる区間がない。
                  itr++;
                }
            } 
            
            {//完全に内包される区間を消し、右端も処理。
                while(1) {
                    auto[l, r] = *itr;
                    if(R < l) break;//共通区間なし
                    if(r <= R) {//新たな区間が内包する。
                      s.erase(itr++);
                      sum -= (r - l) + 1;
                    }
                    else {//共通区間がある。（右端）
                      s.erase(itr++);
                      sum -= (r - l) + 1;
                      R = r;
                      break;
                    }
                }
                s.emplace(L, R);
                sum += (R - L) + 1;
            }
            return;
        }

        void erase__(T x) {
            auto itr = prev(s.lower_bound(make_pair(x+1, x+1)));
            auto [l, r] = *itr;
            if(l <= x && x <= r) {//存在するならば
                sum--;
                s.erase(itr);
                if(l != x)s.emplace(l, x-1);
                if(r != x)s.emplace(x+1, r);
            }
            return;
        }

        void erase__(T L, T R) {
            //合計は、道中毎回引く。
            if(L > R) return;
             auto itr = prev(s.lower_bound(make_pair(L+1, L+1)));
              {//まず、左端を処理。
                auto [l, r] = *itr;
                if(l <= L && R <= r) {//消す区間が内包される。
                    s.erase(itr++);//間を削除
                    sum -= (R - L) + 1;
                    if(l < L) s.emplace(l, L-1);
                    if(R < r) s.emplace(R+1, r);
                    return;
                }
                else if(l == L && r <= R) {//消す区間が内包する。
                    s.erase(itr++);//削除
                    sum -= (r - l) + 1;
                }
                else if(l < L && L <= r && r < R) {//重なる部分がある。
                    s.erase(itr++);//削除
                    sum -= (r - l) + 1;
                    s.emplace(l, L-1);
                    sum += (L-1 - l) + 1;
                }
                else {//重なる区間がない。
                  itr++;
                }
            } 

            {//完全に内包される区間を消し、右端も処理。
                while(1) {
                    auto[l, r] = *itr;
                    if(R < l) break;//共通区間なし
                    if(r <= R) {//消す区間が内包する。
                      s.erase(itr++);
                      sum -= (r - l) + 1;
                    }
                    else {//共通区間がある。（右端）
                      s.erase(itr++);
                      sum -= (r - l) + 1;
                      s.emplace(R+1, r);
                      sum += (r - (R+1)) + 1;
                      break;
                    }
                }
            }
            return;
        }

      

    public:
        bool count(T x) {//xが存在するか。
            auto itr = prev(s.lower_bound(make_pair(x+1, x+1)));
            auto [l, r] = *itr;
            return l <= x && x <= r;
        }//O(logN) 注 : Nは、コンテナに含まれる区間の個数を表す。


        void insert(T x) {//既にあったら何もしない。
            insert__(x);
        }//O(logN)

        void insert(T l, T r) {//[l, r]の区間内の要素を存在する状態にする。
            insert__(l, r);
        }//O(logN)

        void erase(T x) {//存在しなかったら何もしない。
            erase__(x);
        }//O(logN)

        void erase(T l, T r) {//[l, r]の区間内で、setに存在するものを削除。
            erase__(l, r);
        }//O(logN)

        T mex(T x) {//通常のmexはx = 0  [x, LLONG_MAX]で存在しない最小値
            auto itr = s.lower_bound(make_pair(x+1, x+1));
            itr--;
            auto [l, r] = *itr;
            if(l <= x && x <= r) return r+1;
            else return x;
        }//O(logN)

        int size() {//区間の総数を返す。
            return int(s.size()) - 2;
        }//O(1)

        long long getsum() {//存在する要素の総数を返す。
            return sum;
        }//O(1)

        //@brief 区間を管理するset( i], [i+1 を統合しないver)
        //全ての区間を走査する場合、番兵である区間が二つあることに注意。
};