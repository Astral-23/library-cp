#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include<bits/stdc++.h>
using namespace std;
#include "../DetaStructures/SegTree_with_binary-search.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'



struct Monoid {
    int a;
   
    Monoid(){}
      
    Monoid(int _a) : a(_a) {
      
    }

    friend Monoid op(const Monoid& l, const Monoid& r) {
        return l.a + r.a;
    }

    friend Monoid update(const Monoid& l, const Monoid& r) {
		return r;
   
    }

    static Monoid ide() {
       return 0LL;
    }
};


int nex(const Monoid& now) {
	return now.a >= 1;
}


int main() {
	ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
	SegTree<Monoid> seg(N);
	string T;
	cin >> T;
	rep(i, 0, N-1) {
		if(T[i] == '1') seg.set(i+1, 1);
	}
	seg.init();

	while(Q--) {
        int t, k;
        cin >> t >> k;
        if(t==0) {
            seg.change(k+1, 1);
        }
        else if(t==1) {
			seg.change(k+1, 0);
        }
        else if(t==2) {
            if(seg.get(k+1, k+1).a) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(t==3) {
			int res = seg.min_right(k+1, nex);
		    if(res==-1) cout << -1 << '\n';
			else cout << res-1 << '\n';
        }
        else {
           int res = seg.max_left(k+1, nex);
		   if(res==-1) cout << -1 << '\n';
		   else cout << res-1 << '\n';
		}
    }
}


