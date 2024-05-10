
template<typename T>
struct Matrix  {
  using ll = long long;
  int h, w;
  vector<vector<T>> d;
  Matrix() {}
  Matrix(int h, int w, T val = 0): h(h), w(w), d(h, vector<T>(w, val)){}
  Matrix& unit() {
    assert(h == w);
    for(int i = 0; i < h; i++) {
      d[i][i] = 1;
    }
   return *this;
  }
  const vector<T>& operator[](int i) const{return d[i];}
  vector<T>& operator[](int i) {return d[i];}
  Matrix operator*(const Matrix&a) const{
    assert(w == a.h);
    Matrix r(h, a.w);
    for(int i = 0; i < h; i++) {
      for(int k = 0; k < w; k++) {
        for(int j = 0; j < a.w; j++) {
          r[i][j] += d[i][k] * a[k][j];
        }
      }
    }
    return r;
  }
  Matrix pow(ll t) const {
    assert(h == w);
    if(!t) return Matrix(h, h).unit();
    if(t == 1) return *this;
    Matrix r = pow(t >> 1);
    r = r * r;
    if(t&1) r = r*(*this);
    return r;
  }
};
/*
@brief 行列の型
*/