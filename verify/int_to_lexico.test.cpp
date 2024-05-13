
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;
#define rep(i, s, f) for(long long i = s; i <= f; i++)
#include "../Math/int_to_lexico.hpp"
#include "../Utilities/timer.hpp"
#define ENDL '\n'


int main() {
	rep(i,1,18) p10[i] = p10[i-1] * 10;


	ll B = 10000000;
	vector<string> vs(B+1);
	rep(i, 0, B) vs[i] = to_string(i);
	sort(vs.begin(), vs.end());

	tim.start();

	rep(i, 0, B) {
		assert(stoll(vs[i]) == kth(i, B));
	}

	tim.out();
	


}