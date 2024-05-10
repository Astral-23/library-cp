#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../Graph/hld.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'


struct Monoid {
    long long a;
   
    Monoid(){}
      
    Monoid(long long _a) : a(_a) {
      
    }

    friend Monoid op(const Monoid& l, const Monoid& r) {
      return l.a + r.a;
    }

    friend Monoid update(const Monoid& l, const Monoid& r) {
        return l.a + r.a;
    }

    static Monoid ide() {
       return 0LL;
    }
    
};


int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++)cin >> A[i];
    vector<vector<int>> G(N+1);
    for(int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    HLD<Monoid> hld(G, 1);

    for(int i = 1; i <= N; i++) hld.set(i, A[i]);
    hld.init();

    while(Q--) {
        int t;
        cin >> t;
        if(t == 0){
            long long p, x;
            cin >> p >> x;
            p++;
            hld.change(p, x);
        }
        else {
            int u, v;
            cin >> u >> v;
            u++, v++;
            cout << hld.get(u, v).a << '\n';

        }
    }
}