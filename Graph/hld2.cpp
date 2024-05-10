template <typename X, typename EDGE>
struct HL {
  vector<int> siz;//[元の頂点番号] = サイズ
  vector<int> num;//[元の頂点番号] = 振り直した頂点番号
  vector<int> numrev;
  vector<int> par;//[振られた] = 振られた 自分の親
  vector<int> head;//[振られた番号] = 振られた番号 自分の連結成分の頭
  int N;
  vector<vector<X>> dat;//セグ木用の配列、[0](番号が小さい, 番号がでかい)の順で結合   [1](でかい, 小さい)
  
  int size = 1;
  X def;
  

  HL(int _N, vector<vector<EDGE>>& G, X _def): N(_N), def(_def) {
    par.resize(N+1);
    iota(par.begin(), par.end(), 0);
    siz.resize(N+1, 1);
    num.assign(N+1, -1);
    numrev.resize(N+1, -1);
    head.resize(N+1);
    while(size < N) size <<= 1;
    dat.resize(2);
    dat[0].assign(size*2, def), dat[1].assign(size*2, def);

    auto dfs_siz = [&](auto dfs_siz, int now, int prev) -> void {
      int sum = 1;
      for(int i = 0; i < G[now].size(); i++) {
        EDGE& e = G[now][i];
        if(e.to == prev) continue;
         dfs_siz(dfs_siz, e.to, now);
         sum += siz[e.to];
      }
      siz[now] = sum;
      return;
    };
    dfs_siz(dfs_siz, 1, -1);
    for(int i = 1; i <= N; i++) {
      sort(G[i].begin(), G[i].end(), [&](EDGE& a, EDGE& b) {
        return siz[a.to] > siz[b.to];
      });
    }

    int idx = 1;
    auto dfs_bunkai = [&](auto dfs_bunkai, int now, int prev, int hed) -> void {
      num[now] = idx;//番号付
      numrev[idx] = now;
      idx++;
      par[num[now]] = prev;//親の頂点   //1だけは直前も自分も1
      if(hed == -1)hed = num[now];
      head[num[now]] = hed;

      bool flag = true;
     
      for(int i = 0; i < G[now].size(); i++) {
        if(num[G[now][i].to] != -1) continue;
        if(flag) dfs_bunkai(dfs_bunkai, G[now][i].to, num[now], hed), flag = false;
        else dfs_bunkai(dfs_bunkai, G[now][i].to, num[now], -1);
      }
      return;
    };
    dfs_bunkai(dfs_bunkai, 1, 1, -1);
  }
  // 振り終わった
  //////////////////////////////////////////
  
  
  void change(int pos, X x) { //入 : 元番号
    pos = num[pos];//振り当てた番号で扱う！！！
    pos = size + pos - 1;
    dat[0][pos] = update(dat[0][pos], x);
    dat[1][pos] = update(dat[1][pos], x);
    while(pos >= 2) {
      pos >>= 1;
      dat[0][pos] = op(dat[0][pos * 2], dat[0][pos * 2 + 1]);
      dat[1][pos] = op(dat[1][pos * 2 + 1], dat[1][pos * 2]);
    }
  }

  X query(int a, int b, int t) {// 入 : 新番号//半開区間 t...結合の向き
    X L = def, R = def;
    a += size - 1, b += size - 1;
    while(a < b) {
      if(t == 0) {
        if(a & 1) L = op(L, dat[0][a++]);
        if(b & 1) R = op(dat[0][--b], R);
      }
      else {
        if(a & 1) R = op(dat[1][a++], R);
        if(b & 1) L = op(L, dat[1][--b]);
      }
      a >>= 1, b >>= 1;
    }
    return  op(L, R);
  }

  X get(int s, int t) {// 入 : 元番号
    int w = num[getLCA(s, t)];//lcaで左右に分ける
    s = num[s];
    t = num[t];
    X L = def, R = def;
    while(s != w) {//sはのぼる（頂点番号がでかい方から小さい方に行く)。s → t を列で考えるとわかりやすい。 sは左、tは右
      int hed = max<int>(head[s], w+1);
      L = op(L, query(hed, s+1, 1)); 
      if(hed != w)  s = par[hed];
      else s = w;
    }   
    L = op(L, query(w, w+1, 1));//葉から上の方へ
    while(t != w) {//tはくだる（頂点番号が小さい方からでかい方に行く）。
      int hed = max<int>(head[t], w+1);
      R = op(query(hed, t+1, 0), R); //葉から上の方へ
      if(hed != w)  t = par[hed];
      else t = w;
    }
    //R = operation(query(1, size+1, w, w+1, 1), R); これをしてないので、RはまだLCAに辿り着いてない。
    return op(L, R);
  }

  int getLCA(int a, int b) {//入 : 元番号  出 : 元番号
    a = num[a];
    b = num[b];
    while(true) {
      if(a > b) swap(a, b);
      if(head[a] == head[b]) return numrev[a];
      b = par[head[b]];
    }
  }

  int parent(int a) {//入 : 元番号
    return numrev[par[num[a]]];
  }
};

//いじるところ。
struct Monoid {
 

    friend Monoid op(const Monoid& l, const Monoid& r) {
        Monoid res;
      
        return res;
    }

    friend Monoid update(const Monoid& l, const Monoid& r) {
    
    }
};

Monoid def = {1, 0};

struct edge {
    long long to;

};

/*
@brief HLD(可換)
*/