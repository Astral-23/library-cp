
struct sectional_primes {
    /*
    [L, R]の整数を素数判定：素因数分解する。
    コンストラクタ：素数判定
    O(√Rloglog√R + (R - L)loglog(R-L))？
    [1, 10^6]で134ms [10^12, 10^12 + 10^6]で350ms程
  
    conduct()を実行すると、素因数分解が実行される。
    O((R - L)log(R))
    参考 : 区間長とRの大きさが速度に影響。
    [1, 10^6]で300ms, [10^12, 10^12 + 10^6]で550ms程
    isprime[i]で、iが素数かどうかがわかる。  L <= i <= R || 1 <= i <= √R O(1)
    get[i]で、iの素因数分解の結果が得られる  L <= i <= R  O(log(i))
    */
    long long L, R, M;
    bool conducted = false;
    vector<bool> small;//small[i] := iが素数かどうか i <= √R
    vector<vector<long long>> large;//large[i] := i+L の相異なる素因数の集合
    vector<vector<pair<long long, long long>>> large_res;
    vector<vector<long long>> aux;// aux[i] := large[i]の素因数の積、つまりi + Lの素因数の積（素数判定用）
  
    sectional_primes(long long _L, long long _R) : L(_L), R(_R) {
        assert(R >= 1 && L <= R);
        M = sqrt(R);
        small.resize(M + 1, true);
        small[0] = false;
        small[1] = false;
        large.resize(R - L + 1);
        large_res.resize(R - L + 1);
    
        for(long long i = 2; i * i <= R; i++) {
            if(!small[i]) continue;
            for(long long j = i * 2; j <= M; j += i) {
                small[j] = false;
            }
            for(long long j = (L + i - 1)/i * i; j <= R; j += i) {
                large[j - L].push_back(i);
            }
        }
    //√R以下の素因数は全て列挙し終えた。ここからは√R以上の素因数を列挙。ちなみに、√R以上の素因数は各数につき最大て1つ。
    //ここまでO(√Rloglog√R + (R - L)loglog(R-L))
    }
    

    private:

        void conduct() {
            for(long long i = L; i <= R; i++) {
                long long num = i;
                for(long long x : large[i - L]) {
                    if(num < x) break;
                    long long cnt = 0;
                    while(num % x == 0) num /= x, cnt++;
                    large_res[i - L].emplace_back(x, cnt);
                }
                if(num != 1) large[i-L].push_back(num), large_res[i-L].emplace_back(num, 1);
            }
          //O((R - L)log(R))
        }
        
    

    public:

        bool isprime(long long x) {//[-無限, √R] または [L, R]について、素数判定  それ以外は未定義
          if(x <= 1) return false;
          if(x <= M) return small[x];
          if(!conducted) return large[x - L].size() == 0;//√R以下の素因数がない⇔xが素数
          else return large[x - L].size() == 1;//素因数分解済み。
        }//O(1)  
      
        vector<pair<long long, long long>> get(long long x) {//[L, R]について、素因数分解の結果を返す {素因数, 指数}の配列
            if(!conducted) conduct();
            return large_res[x - L];
        }//初回いっぱい 以降O(1)
};

/*
@brief 素数篩(左端任意)
*/