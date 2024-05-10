#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../DataStructures/static2Drectanglesum.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  static2Drectunglesum seg;
  for(int i = 0; i < N; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    seg.add(x, y, w);
  }
  seg.init();
  for(int qi = 0; qi < Q; qi++) {
    long long l, d, r, u;
    cin >> l >> d >> r >> u;
    r--, u--;
    cout << seg.get(l, r, d, u) << '\n';
  }
  
}