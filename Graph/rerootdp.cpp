template<typename tdp>
struct TDP_MAIN {
    int N;
    vector<vector<pair<int, int>>> G;
    vector<vector<tdp>> dp;//dp[now][i] :=  全体の根をnowとした時、 G[now][i]を根とする部分木の結果
    vector<tdp> ans;
  
    TDP_MAIN (int _N) : N(_N) {G.resize(N+1), dp.resize(N+1), ans.resize(N+1);}


    private:
        tdp dfs(int now, int prev) {
            tdp res = tdp();
            int deg = G[now].size();
            dp[now].resize(deg);
            for(int i = 0; i < deg; i++) {
                int to = G[now][i].first;
                if(to == prev) continue;
                dp[now][i] = dfs(to, now);
                res = op(res, E(dp[now][i], G[now][i].second));
            }
            return res.addRoot(now);
        }


        void bfs(int now, const tdp& dpPar, int prev) {
            int deg = G[now].size();
            for(int i = 0; i < deg; i++) if(G[now][i].first == prev) dp[now][i] = dpPar;
            
            vector<tdp> dpsumL(deg+1, tdp()); //dpsumL[i] := [0, i-1]
            vector<tdp> dpsumR(deg+1, tdp()); //dpsumR[i] := [i, deg-1]


            for(int i = 0; i < deg; i++) dpsumL[i+1] = op(dpsumL[i], E(dp[now][i], G[now][i].second));
            for(int i = deg-1; i >= 0; i--) dpsumR[i] = op(dpsumR[i+1], E(dp[now][i], G[now][i].second));
            
            reflect(now, dpsumL[deg].addRoot(now));

            for(int i = 0; i < deg; i++) {
                int to = G[now][i].first;
                if(to == prev) continue;
                tdp d = op(dpsumL[i], dpsumR[i+1]);
                bfs(to, d.addRoot(now), now);

            }
        }

		void reflect(int now, const tdp& res) {
		    ans[now] = res;    
            return;        
        }

    public:

	    void add_edge(int u, int v, int id) {
			G[u].emplace_back(v, id);
			G[v].emplace_back(u, id);
	    } 
        
        vector<tdp> exe() {
            dfs(1, -1); tdp tmp = tdp();
            bfs(1, tmp, -1);
            return ans;
        }

		/*
		  TDP_MAIN<tdp> (N, G)
		  @brief 全方位木DP
		  add_edge(u, v, id) ... (u, v)間に辺番号がidの辺を追加する。
		  exe()...実行
		
		  諸注意：
		    ・木DPで一時変数に任せてた物は、全方位木DPでは明示的に持つ必要がある。
			E...辺重みを追加。一様ならaddRootの時で良い。
			op...集約。
			
		*/
};


struct TDP {

	ll val;

	TDP (ll _val = 0) :  val(_val) {}
    
	friend TDP E (const TDP& l, int id) {
	

	}

    friend TDP op (const TDP& l, const TDP& r)  {
		
    }

	
    TDP addRoot (int now)  { //*thisが子の集約結果
	
    }

};
