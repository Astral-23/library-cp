vl p10(19, 1);

ll count(ll pref, ll r, int k, int M) {//[0, r]において、prefixがprefと一致する数字は何個あるか（リーディング0は省く。  O(1)
    r++;
    if(pref==0) return 1LL;
    ll res = 0;
	if(M >= k) {
	    res += (p10[M-k] - 1) / 9;
    	ll nl = pref * p10[M - k];
	    ll nr = (pref+1) * p10[M - k];
	    nr = min(nr, r);
	    res += max(0LL, nr - nl);
	}
	return res;

}

ll kth(ll k, ll r) {//[0, r]で辞書順k番目の数字を返す。 0-indexed(kth(0) = 0)  10 * log(r) 
    k++;
	if(k==1) return 0LL;
    int M = (to_string(r)).size();
	ll pref = 0;
	rep(i, 1, M) {
		if(k==1) break;
		k--;
		rep(nex, 0, 9) if(!(i==1 && nex == 0)){
			ll c = count(pref*10+nex, r, i, M);
			if(k <= c) pref = pref * 10 + nex, nex = 9;
			else k -= c;
		}
	}
	return pref;

}
/*
@brief [0, r]で辞書順K番目の整数   
p10をどこかで計算しておく。
verified with https://atcoder.jp/contests/arc078/submissions/53435109
あるいは r = 10000000でのストレステスト
補足：整数の辞書順比較について、（リーディング0を除いた)桁数が等しいならば、大小関係と辞書順が一致
*/