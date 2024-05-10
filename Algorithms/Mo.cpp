struct Mo {
  int N;
  int Q;
  vector<pair<int, int>> lr;
  vector<int> querynum;
  int width;
  int nowl = 0;
  int nowr = 0;
  //答えを記録する配列と一時的な答えを記録する変数
  vl answer;
  long long ans = 0;
  //型は問題によって変わるかも


  Mo (int n, int q, vector<pair<int,int>> &query) {
    N = n;
    Q = q;
    lr.resize(Q+1);
    answer.resize(Q+1);
    querynum.resize(Q+1);
    rep(i, 1, Q) {
      querynum[i] = i;
    }
    //width = max(1, int(N/sqrt(Q)));
    width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
    rep(i, 1, Q) {
      lr[i] = query[i];
    }

    sort(querynum.begin()+1, querynum.end(), [&](int i, int j) {
      if(lr[i].first/width != lr[j].first/width) {
        return lr[i].first < lr[j].first;
      }
      else {
        int group = lr[i].first/width;
        if(group%2==0) {
          return lr[i].second < lr[j].second;
        }
        else {
          return lr[i].second > lr[j].second;
        }
      }
    });
  }

  void add(int id) {
 

  }

  void del(int id) {

  }


  void excute() {
    for(int i = 1; i <= Q; i++) {
      while(nowl > lr[querynum[i]].first) nowl--, add(nowl);
      while(nowr < lr[querynum[i]].second) nowr++, add(nowr);
      while(nowl < lr[querynum[i]].first) del(nowl), nowl++;
      while(nowr > lr[querynum[i]].second) del(nowr), nowr--;
      answer[querynum[i]] = ans;
    }
  }
};

/*
@brief Mo 
*/