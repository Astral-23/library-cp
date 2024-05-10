const int K = 60;
struct bitbase { //xor基底を作成する オーダー：60 * N    NlogNと言えば正確か
  vector<ll> d;

  bitbase() : d(K) {}
  void add(ll x) {
    x = tomin(x);
    if(x == 0)return ;//xはなんの代表にもなれない
    per(i, K-1, 0) { //i桁目の代表になる
      if(x >> i & 1) {
        rep(j, 0, K-1) {
          if(d.at(j) >> i & 1) d.at(j) ^= x; //元あった基底とxorをとっておく（掃き出す）
        }
        d.at(i) = x;
        return ;
      }
    }
  }
  ll tomin(ll x) { //まだ基底が存在しない && xはその基底になれる　ようなbitを求める為の前処理
    per(i, K-1, 0) {
      if(x >> i & 1) x ^= d.at(i);
    }
    return x;
  }
  ll operator[](int i) const {return d[i-1];}
  ll& operator[](int i) {return d[i-1];}
};

/*
@brief xor基底
*/