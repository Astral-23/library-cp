struct notlinear_sieve {
    int N;

    notlinear_sieve(int _N) : N(_N) {
        assert(1 <= N);
        large.resize(N + 1);
        iota(large.begin(), large.end(), 0);
        large_res.resize(N + 1);
    
        for(int i = 2; i * i <= N; i++) {
            if(large[i] != i) continue;
            for(int j = i * 2; j <= N; j += i) {
                if(large[j] == j) large[j] = i;
            }
        }
        //O(NloglogN)
    }


    private:
        vector<int> large;//割り切る最小の素因数
        vector<vector<pair<int, int>>> large_res;//素因数分解の結果（conductして初めて埋まる）
        vector<int> div_cnt;
        bool conducted = false;
        bool divcntinited = false;
    
        void conduct() {
            conducted = true;
            for(long long i = 2; i <= N; i++) {
                long long num = i;
                while(large[num] != num) {
                    long long tmp = num;
                    long long cnt = 0;
                    while(tmp % large[num] == 0) cnt++, tmp /= large[num];
                    large_res[i].emplace_back(large[num], cnt);
                    num = tmp;
                }
                if(num != 1) large_res[i].emplace_back(num, 1LL);
            }
            //この処理にO(NlogN)
        }
        
        int divcnt__(int x) {
            if(!conducted) conduct();
            auto ps = get(x);
            int res = 1;
            for(auto [p, c] : ps) res *= (c+1);
            return res;
        }

        vector<int> divs__(int x) {
            if(!conducted) conduct();
            vector<int> res;
            auto ps = get(x);

            auto dfs = [&](auto dfs, long long id, long long val) -> void {
                if(id == ps.size()) {
                    res.push_back(val);
                    return;
                }

                auto [p, c] = ps[id];
                for(int i = 0; i <= c; i++) {
                    dfs(dfs, id+1, val);
                    val *= p;
                }
            };

            dfs(dfs, 0, 1);
            return res;
        }
    

    public:

        vector<int> primes(int r) {//[2, r]に収まる素数が昇順で入った配列を返す。
            vector<int> res;
            for(long long i = 2; i <= r; i++) if(isprime(i)) res.push_back(i);  
            return res;
        }//O(r)


        bool isprime(int x) {//xは素数か 
            if(x <= 1) return false;
            return large[x] == x;
        }//O(1)


        int divcnt(int x) {//xの約数の個数を返す。
            return divcnt__(x);
        }//O(logN) 注：初回O(NlogN)

        vector<int> divs(int x) {//xの約数を適当な順で入れた配列を返す。
            return divs__(x);
        }//O(約数の個数)  x <= 10^18で大凡 O(x ^ (1/3))  注 : 初回O(NlogN)
      

        vector<pair<int, int>> get(int x) {//xを素因数分解した結果 {素因数, 次数}のペアが入った配列
            if(!conducted) conduct();
            return large_res[x];
        }//O(1) 注： 初回O(NlogN)
  

    //@brief 素数篩
    //豆知識:Xの約数の個数は精々X^(1/3)程度。(X>=10^18以降は様相が変わるが)
    //素因数分解について、特定の数字xについてのみlog(x)で実行することもできる。

};notlinear_sieve sieve();