
#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include<bits/stdc++.h>
using namespace std;
#include "/Users/library-cp/library-cp/Math/matrix.hpp"
#include "/Users/library-cp/library-cp/Utilities/modint998.hpp"
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#define ENDL '\n'

int main() {

	int N, K;
	cin >> N >> K;
	Matrix<mint> A(N, N, 0);
	rep(i,0,N-1) rep(j,0,N-1) cin >> A[i][j];
	A = A.pow(K);
	rep(i,0,N-1) {
		rep(j,0,N-1) cout << A[i][j] << " ";
		cout << '\n';
	}

    
}





