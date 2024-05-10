#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../Graph/hld.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'

struct Monoid {
    ll a;
   
    Monoid(ll _a = 0) : a(_a) {}
      

    friend Monoid op(const Monoid& l, const Monoid& r) {
      return l.a + r.a;
    }

    friend Monoid update(const Monoid& l, const Monoid& r) {
        return l.a + r.a;
    }

    static Monoid ide() {
       return ll(0);
    }
    
};




int main() {
	
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
   

    int N, Q;
    cin >> N >> Q;
	vl A(N+1);
	rep(i,1,N) cin >> A[i];
    vector<vector<int>> G(N+1);
	rep(i,2,N) {
		int p;
		cin >> p;
		p++;
		G[p].push_back(i);
		G[i].push_back(p);
	}

	HLD<Monoid> hld(G, 1);
	rep(i,1,N) hld.set(i, Monoid(A[i]));
	hld.init();




	while(Q--) {
		int type;
		cin >> type;

		if(type==0) {
			int u, x;
			cin >> u >> x;
			u++;
			hld.change(u, Monoid(x));
		}
		else {
			int u;
			cin >> u;
			u++;
			cout << hld.subtree(u).a << '\n';
		}
	}

  

    


}
