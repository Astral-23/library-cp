template<typename T>
int LIS(vector<T> A, int N, int indexed) {
    vector<int> dp(N+1, 0);
    vector<long long> L(N+1, LLONG_MAX);
    L[0] = -LLONG_MAX;
  
    for (int i = indexed; i <=N; i++) {
        auto temp = lower_bound(L.begin(), L.end(), A[i]);
        int index = distance(L.begin(), temp - 1);
        dp[i] = index + 1;
        L[index+1] = min<long long>(L[index + 1], A[i]);    
    }
 
    int answer = 0;
    for(int i = indexed; i <= N; i++) {
        answer = max(answer, dp[i]);
    }
    return answer;
}

template<class T>
int LDS(vector<T> A, int N, int indexed) {//1-indexed
	vector<int> dp(N+1, 0);
    vector<long long> L(N+1, -LLONG_MAX);
    L[0] = LLONG_MAX;
  
    for (int i = indexed; i <= N; i++) {
    	int li = 0;
    	int ri = N-indexed;
        while(li < ri) {
    		int mi = (li+ri+1)>>1;
    		if(L[mi] > A[i]) li = mi;
    		else ri = mi-1;
    	}
          dp[i] = li + 1;
          L[li+1] = max<long long>(L[li + 1], A[i]);
      }
     
      int answer = 0;
      for  (int i = indexed; i <= N; i++) {
        answer = max(answer, dp[i]);
      }
      return answer;
}

/*
@brief LIS/LDS
*/