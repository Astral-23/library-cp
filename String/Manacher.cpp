struct Manacher {
  string S;
  int N;
  int nn;
  vi R;
  Manacher(string &T) {
    S = T;
    N = S.size();
    string temp = "";
    rep(i, 0, N-1) {
      temp += S[i];
      if(i != N-1)temp += "$";
    }
    nn = temp.size();
    R.resize(nn);

    int c = 0;
    for(int i = 0; i < nn; i++) {
      int l = 2 * c - i;
      if(i + R[l] < c + R[c]) {
        R[i] = R[l];
      }
      else {
        int j = c+R[c] - i;//とりあえず保証されている半径
        while(i - j >= 0 && i + j < nn && temp[i-j] == temp[i+j]) j++;//i文字目を含めて左にあるのは i + 1文字　よって、 (i + 1) - j >= 0が守られる必要がある i文字目を含めて右にはnn - i文字あるよってnn - i >= j
        R[i] = j;
        c = i;
      }
    }
  }

  int get(int idx) {//奇数長
    return (R[2 * (idx-1)]+1)/2;
  }

  int get(int idx, int tuginosoezi) {//偶数長
    int m = 2 * (idx-1) + 1;
    return R[m]/2;
  }
};
/*
@brief Manacher
回文の半径を返す
*/