#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include<bits/stdc++.h>
using namespace std;
#include "../DataStructures/li_chao_tree.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'


struct que {
    ll t, a, b;
    que(int _t, ll _a, ll _b) : t(_t), a(_a), b(_b){}
    que(){}
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);


  ll N, Q;
    cin >> N >> Q;
    vl A(N+1), B(N+1);
    rep(i,1,N) {
        ll a, b;
        cin >> a >> b;
        A[i] = a, B[i] = b;
    }
    vector<que> qs(Q+1);
    vector<ll> xs;

    rep(qi, 1, Q) {
        ll t, a, b;
        cin >> t;
        if(t == 0) {
            cin >> a >> b;
        }
        else cin >> a;
        qs[qi] = que(t, a, b);

        if(t == 1) {
            xs.push_back(a);
        }
    }
    sort(xs.begin(), xs.end());
    unique(xs.begin(), xs.end());
    li_chao_tree<ll> tr(xs);
    rep(i,1,N) {
        tr.add_line(A[i], B[i]);
    }

    rep(qi, 1, Q) {
        auto [t, a, b] = qs[qi];
        if(t == 0) {
            tr.add_line(a, b);
        }
        else {
            cout << tr.get(a) << ENDL;
        }
    }
    
    
  
}
