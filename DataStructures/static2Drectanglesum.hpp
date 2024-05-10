template<typename T>
struct CC {
  bool initialized;
  vector<T> xs;
  CC () : initialized(false) {}
  void add(T x) {xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    initialized = true;
  }

  int operator()(T x) {//値(x)の圧縮後の値（何番目に大きかった？） O(logN)
    if(!initialized) init();
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
    //1-indexedである。
    //大きい方に丸めている。{10,  15}の時、(13) = (15) = 2。これは、半開区間を意識している。
  }
  T operator[](int i)  {//[i]番目に大きい値　（圧縮後にiになるのは値なんだ） O(1)
    if(!initialized) init();
    assert(i <= int(xs.size()) && i >= 1);
    return xs[i-1];
  }
  int size()  {
    if(!initialized) init();
    return xs.size();
  }
};

//点の座標がマイナスでも行けると思います(座標圧縮で正になるので）
//depend on CC library(座標圧縮)
struct static2Drectunglesum {
    //ref : https://onedrive.live.com/view.aspx?resid=CD510BE428DBA1E7%21106&authkey=!AFD6EO1-AReoPBk

    vector<long long> xs;//点の情報(indexベースで扱うと便利)
    vector<long long> ys;//点の情報
    vector<long long> ws;//点の重み
    vector<vector<long long>> sum;//各頂点の累積和
    CC<long long> nxs;//xsの座標圧縮
    int N;//座標圧縮したのちのxの頂点数の2冪


    vector<vector<pair<long long, long long>>> dat;//(y座標、重み)
    vector<vector<int>> L;//L[i][k] := dat[i][k]の、左の子での添え字(dat[i][k]が右の子由来の時は、dat[i]内の次の左の子のやつと一致させる)
    vector<vector<int>> R;//R[i][k] := dat[i][k]の、右の子での添え字(L, R共に半開区間)

     /*
        L[i][k] には、「dat[i]でk番目の値は、
            左の子に存在する : そのindex (複数その値が存在するのならば、一番左が子でも一番左のを指していれば後はどうでも良い。)
            存在しない : 「初めてk番目の値を超える値」のindex(存在しないなら配列のサイズを入れとく)
         を収めれば良い。（こうすると、二分探索した結果の範囲が正しく子に引き継がれる。
         Rも同様。
     */

    private:
        void init__() {
            nxs.init();
            int n = nxs.size();
            N = 1; 
            while(N < n) {
              N <<= 1;
            }
            dat.resize(2 * N);
            sum.resize(2 * N);
            L.resize(N);
            R.resize(N);
            
            //一番下の段に入れる。O(NlogN)
            for(int i = 0; i < int(xs.size()); i++) {
                int id = nxs(xs[i]);//xs[i]の座標圧縮後の値 1-indexedである。
                int pos = id + N - 1;
                dat[pos].emplace_back(ys[i], ws[i]);//累積和を取る為に、重みもペアで入れておく。
            }

            //もうxs, ys, wsは必要無いので捨てる(メモリ削減)
            xs.clear();
            ys.clear();
            ws.clear();


            //葉の中身について、y座標昇順でsortする。計算量はO(NlogN)で抑えられる。
            for(int i = 1 + N - 1; i < int(dat.size()); i++) {
                sort(dat[i].begin(), dat[i].end());
            }

            //ボトムアップにマージしていく。
            for(int i = N - 1; i >= 1; i--) {
                dat[i].resize(dat[i<<1].size() + dat[i<<1|1].size());
                merge(begin(dat[i<<1]), end(dat[i<<1]), begin(dat[i<<1|1]), end(dat[i<<1|1]), begin(dat[i]));
            }
        
            //ここまでが普通のrange tree
  

            //葉以外の頂点について、LとRを埋めていく。
            for(int i = 1; i <= N-1; i++) {
                L[i].resize(dat[i].size() + 1);//後々半開区間として扱うので、一つ多く取っておくと便利
                R[i].resize(dat[i].size() + 1);

                int li = 0, ri = 0;
                //イメージ : [1]li, ri共に正しい( =0, =0の初期化）。 [2]重複なしの値があるなら、存在する方を一つ進めれば正しい。  [3]重複ありの値があるなら、その値が存在する個数分li, riをそれぞれ進めれば正しい。この時、最初の代入で正しいindexが挿入されており、その後ろの同じ値のindexは使われないのでどうでも良い。（つまり正しい）
                for(int j = 0; j < int(dat[i].size()); j++) {
                    L[i][j] = li, R[i][j] = ri;
                    if(li < int(dat[i<<1].size()) && dat[i<<1][li].first == dat[i][j].first) {
                      li++;
                    }
                    else {
                      //左に存在しないなら右に存在する
                      ri++;
                    }
                }
                L[i][dat[i].size()] = dat[i<<1].size();
                R[i][dat[i].size()] = dat[i<<1|1].size();
            }

            //全ての頂点について、累積和を求める。
            for(int i = 1; i < int(dat.size()); i++) {
                if(int(dat[i].size()) == 0) continue;//頂点が空ならスキップ

                sum[i].resize(dat[i].size(), 0);
                sum[i][0] = dat[i][0].second;
                for(int j = 1; j < int(dat[i].size()); j++) {
                  sum[i][j] = sum[i][j-1] + dat[i][j].second;
                }
            }

        }
        

        long long query(long long sx, long long tx, long long sy, long long ty, int now, long long a, long long b) {//[sx, tx) * [sy, ty)の範囲について答える。今の頂点番号がnowで、今回はx = [a, b)の区間について答える。なお、yは、元の座標から今見ている頂点における添え字に変換されている。
            if(b <= sx || tx <= a) return 0LL;
            else if(sx <= a && b <= tx) {
                if(ty == 0) return 0LL;
                long long res = sum[now][ty-1];//半開区間で渡されるので, ty-1
                if(sy != 0) res -= sum[now][sy-1];
                return res;
            }
            else {
                return query(sx, tx, L[now][sy], L[now][ty], now << 1, a, (a+b) >> 1) + query(sx, tx, R[now][sy], R[now][ty], now << 1|1, (a+b)>>1, b);
            }
        }
  
  
    public:
        void add(long long y, long long x, long long w) {
            xs.push_back(x);
            ys.push_back(y);
            ws.push_back(w);
            nxs.add(x);
        }

        void init() {//before query
            init__();
        }

        long long get(long long sy, long long ty, long long sx, long long tx) {//[sx, tx] ✖️ [tx, ty] 
            tx++, ty++;//半開区間に変更。
            //lower_boundで区間を添字に変える際、半開区間ではl, r共に大きい方に丸めれば良い。
            sy = lower_bound(dat[1].begin(), dat[1].end(), make_pair(sy, -LLONG_MAX)) - dat[1].begin();//y座標をdat[1]における添字に変換。この時、同じy座標がたくさんあるならば、その中で一番左を指してほしいので重みは-LLONG_MAX
            ty = lower_bound(dat[1].begin(), dat[1].end(), make_pair(ty, -LLONG_MAX)) - dat[1].begin();//同様。
            sx = nxs(sx);//x座標を座標圧縮後に変換
            tx = nxs(tx);//同様。
            return query(sx, tx, sy, ty, 1, 1, N+1);
        }
        
};//init忘れずに

/*
@brief 静的で巨大なグリッドの矩形和
*/