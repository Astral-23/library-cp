struct CMB {//must素数
  vector<long long> fac;
  vector<long long> facinv;
  vector<long long> inv;
  long long mod_comb = 0;
  int siz = 1;//半開区間[0, siz)に対応

  CMB (ll _mod) : mod_comb(_mod) {resize(1);}
  void set(long long _mod_comb) {mod_comb = _mod_comb; resize(1); return;} // 最初にresize(1)しないと C(0, 0)でバグる
  void resize(int n) {
    if(n < siz) return;
    int ns = siz;
    while(ns <= n) ns <<= 1;
    fac.resize(ns, 1);
    facinv.resize(ns, 1);
    inv.resize(ns, 1);
    for(int i = max(2, siz); i < ns; i++) {
      fac[i] = fac[i-1] * i % mod_comb;
      inv[i] = mod_comb - inv[mod_comb%i] * (mod_comb/i)%mod_comb;
      facinv[i] = facinv[i-1] * inv[i] % mod_comb;
    }
    siz = ns;//忘れない。
    return ;
  }
  

  long long B(int n) { //階乗
    resize(n);
    return fac[n];
  }

  long long invB(int n) {//階乗の逆元
    resize(n);
    return facinv[n];
  }

  long long C(int n, int k) { //n種類から重複なしk個選ぶ時の集合の総数
    if(n < k) return 0LL;
    if(n < 0 || k < 0) return 0LL;
    resize(n);
    return fac[n] * (facinv[k] * facinv[n-k]%mod_comb)%mod_comb;
  }

  long long H(int n, int k) { //n種類の物から重複を許してk個選ぶ時の集合の総数
    resize(n+k-1);
    return C(n+k-1, k);
  }

  long long Cn(int n) { //カタラン数
    resize(2 * n);
    return C(2*n, n) * inv[n+1] % mod_comb;
  }
};
CMB cmb(mod);

/*
@brief コンビネーション
*/