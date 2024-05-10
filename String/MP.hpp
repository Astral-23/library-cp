vector<int> MP(string S) {
  int N = S.size();
  vector<int> res(N+1, -1);
  int j = -1;
  for(int i = 0; i <= N-1; i++) {
    while(j >= 0 && S.at(i) != S.at(j)) j = res.at(j);
    j++;
    res.at(i+1) = j;
  }
  return res;//結果は1-indexed つまり res[i] := [1, i]について。
}
/*
@brief MP法
res[i] := Sの[1, i]について、prefixとsuffixの共通文字列長を返す(但し、長さi未満とする)
*/