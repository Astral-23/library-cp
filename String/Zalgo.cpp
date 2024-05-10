vl Z_algorithm(string S) {
  ll N = S.size();
  ll c = 0;
  vl res(N+1, 0);
  rep(i, 2, N) {
    ll l = i - c; //対応する黒点線の左端の座標
    if(i + res.at(l) < c + res.at(c)) {
      res.at(i) = res.at(l);
    }
    else {
      ll j = max(0LL, c + res.at(c) - i);//何文字被ってたか 次はj + 1文字目以降を調べれば良い。
      while(i + j <= N && S.at(j) == S.at(i + j))j++;
      res.at(i) = j;
      c = i;
    }
  }
  return res;
}
/*
@brief Z_algorithm
res[i] := [1:]と[i:]の最長共通部の長さ
*/