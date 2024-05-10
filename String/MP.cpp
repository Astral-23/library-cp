vl MP(string S) {
  int N = S.size();
  vl res(N+1, -1);
  int j = -1;
  rep(i, 0, N-1) {
    while(j >= 0 && S.at(i) != S.at(j)) j = res.at(j);
    j++;
    res.at(i+1) = j;
  }
  return res;//結果は1-indexed つまり res[i] := [1, i]について。
}
/*
@brief MP方
res[i] := Sの[1, i]について、prefixとsuffixの共通文字列長を返す(但し、長さi未満とする)
*/