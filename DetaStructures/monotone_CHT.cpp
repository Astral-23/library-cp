struct CHT { //最大値ver//最小値なら-1かけるとかして
  struct linear {
    ll a, b;
    linear(ll a = 0, ll b = 0) : a(a), b(b){}
    ll operator()(ll x) const {return a * x + b;}
  };

  deque<linear> ls;
  void add(ll a, ll b) {//前提：傾きが大きくなっていくように追加 
    linear l(a,b);
    assert(ls.size() == 0 || ls.back().a <= l.a);
    while(ls.size() >= 2) {
      const linear& l1 = ls[ls.size() - 2];
      const linear& l2 = ls.back();
      if((l1.b - l2.b) * (l.a - l2.a) < (l2.a - l1.a) * (l2.b - l.b)) break;
      ls.pop_back();
    }
    ls.push_back(l);
  }

  ll operator()(ll x) {//前提 : クエリで聞くx座標は昇順 && 以降の直線の追加無し
    ll res = ls[0](x);
    while(ls.size() >= 2) {
      ll now = ls[1](x);
      if(now < res)break;
      res = now;
      ls.pop_front();
    }
    return res;
  }
};

/*
@brief : 入力が単調なCHT
*/