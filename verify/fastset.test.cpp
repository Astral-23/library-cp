#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include<bits/stdc++.h>
using namespace std;
#include "../DataStructures/fastset.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'



int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  intset cnt(4);
  int N, Q;
  cin >> N >> Q;
  string T;
  cin >> T;
  for(int i = 1; i <= N; i++) {
	if(T[i-1] == '1') cnt.set(i-1);
  }
  cnt.init();
   while(Q--) {
        int t, k;
        cin >> t >> k;
        if(t == 0) {
            cnt.insert(k);
        }
        else if(t==1) {
		   cnt.erase(k);
        }
        else if(t==2) {
            if(cnt.count(k)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(t==3) {
			if(cnt.empty() || cnt.max_element() < k) {
				cout << -1 << '\n';
			}
            else {
				cout << cnt.lower_bound(k) << '\n';
			}
        }
        else {
           if(cnt.empty() || cnt.min_element() > k) {
			cout << -1 << '\n';
		   }
		   else {
			cout << cnt.lower_left_bound(k) << '\n';
		   }
		}
    }
}