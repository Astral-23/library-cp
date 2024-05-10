vi Suffix_Array(string &S, vi &sa) {
  int n = S.size();
  int k;
// vi sa(n+1, -1);が入っていたが、よくわからないので消した(9/3)　未検証
  vi temp(n+1, -1);
  vi rank(n+1, -1);
  for(int i = 0; i <= n; i++) {
    sa[i] = i;
    rank[i] = i < n ? S[i] : -1;
  }

  auto cmp_sa = [&](int i, int j) {
    if(rank[i] != rank[j]) return rank[i] < rank[j];
    else {
      int ri = i + k <= n ? rank[i+k] : -1;
      int rj = j + k <= n ? rank[j+k] : -1;
      return ri < rj;
    }
  };

  for(k = 1; k <= n; k *= 2) {
    sort(sa.begin(), sa.end(), cmp_sa);
    temp[sa[0]] = 0;
    for(int i = 1; i <= n; i++) {
      temp[sa[i]] = temp[sa[i-1]] + (cmp_sa(sa[i-1], sa[i]) ? 1 : 0);
    }
    for(int i = 0; i <= n; i++) {
      rank[i] = temp[i];
    }
  }
  
  return rank;
}

vi make_lcp(string &S, vi &sa) {
  int n = S.size();
  vi lcp(n, -1);
  vi rank(n+1);
  int h = 0;
  lcp[0] = 0;

  rep(i, 0, n) {
    rank[sa[i]] = i;
  }
  rep(i, 0, n-1) {
    int j = sa[rank[i]-1];
    if(h > 0)h--;
    for( ; j + h < n && i + h < n; h++) {
      if(S[j+h] != S[i+h])break;
    }
    lcp[rank[i]-1] = h;
  }
  return lcp;
}

/*
@brief suffix_array
*/