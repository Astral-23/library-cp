ll nto10(string S, ll base) { //O(|S|) 16新数まで対応
  ll res = 0;
  reverse(all0(S));
  while(!S.empty()) {
    ll num = S.back() - '0';
    if(num < 0 || num > 9) num = 9 + S.back() - 'a' + 1;
    res = res * base + num;
    S.pop_back();
  }
  return res;
}
string toN(ll N, ll base) { //O(log_(base)(N)）程　baseが負の時は知らない
  if(N == 0) return "0";
  string ans ="";
  ll MOD = abs(base);
  while(N != 0) {
    ll first = N % MOD;
    while(first < 0) first += MOD;
    ans += to_string(first);
    N -= first;
    N /= base;
  }
  reverse(all0(ans));
  return ans;
}

/*
@brief 10進⇔n進
*/