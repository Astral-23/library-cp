struct LCA {

    LCA(vector<vector<int>>& _G, int _root) : root(_root), G(_G){
		N = int(G.size()) - 1;
        siz.resize(N+1);
        in.resize(N+1, -1);
        rev.resize(N+1);
        par.resize(N+1);
        head.resize(N+1);
		dep.resize(N+1);
		init__();
    }


    private:
        int N=1;
        int root=1;
        vector<vector<int>> G;
        vector<int> siz;
		vector<int> in;
		vector<int> rev;
		vector<int> dep;
        vector<int> par;
        vector<int> head;
	

        int dfs_siz(int now, int prev) {
            siz[now] = 1;
            for(int to : G[now]) {
                if(to == prev) continue;
				dep[to] = dep[now] + 1;
                siz[now] += dfs_siz(to, now);
            }
            return siz[now];
        }

        void dfs_bunkai(int now, int prev, int hed, int& idx) {
            in[now] = idx;
			rev[idx] = now;
            idx++;
            par[now] = prev;
            if(hed == -1) hed = now;
            head[now] = hed;

            bool f = true;
            for(int i = 0; i < int(G[now].size()); i++) {
                if(in[G[now][i]] != -1) continue;
                if(f) dfs_bunkai(G[now][i], now, hed, idx), f = false;
                else dfs_bunkai(G[now][i], now, -1, idx);
            }
        }

        void init__() {
			dep[root] = 0;
            dfs_siz(root, -1);
            for(int i = 1; i <= N; i++) {
                sort(G[i].begin(), G[i].end(), [&](int a, int b) {
                  return siz[a] > siz[b];
                });
            }
            int id = 1;
            dfs_bunkai(root, root, -1, id);
        }
            

        
    
    public:

        int getLCA(int a, int b) {
            while(true) {
               if(in[a] > in[b]) swap(a, b);
               if(head[a] == head[b]) return a;
               b = par[head[b]];
            }
        }

		int dist(int u, int v) {
			int lca = getLCA(u, v);
			return dep[u] + dep[v] - 2 * dep[lca];
		}

		int depth(int v) {
			return dep[v];
		}

		int kth_ances(int v, int k) {
			if(k > dep[v]) return -1;
			while(v >= 0) {
				int r = head[v];
				if(k <= dep[v] - dep[r]) {
					return rev[in[v] - k];
				}
				else {
					k -= dep[v] - dep[r] + 1;
					v = par[r];
				}
			}
			return v;
		}

		int kth_path(int s, int t, int k) {
			int lca = getLCA(s, t);
			int left = dep[s] - dep[lca];
			int right = dep[t] - dep[lca];
			if(0 <= k && k <= left + right) {
				if(k < left) return kth_ances(s, k);
				else return kth_ances(t, left+right-k);
			}
			return -1;
		}

		/*
		LCA(G, root)  コンストラクタ: O(N)  空間 : O(N)
		@brief 木に関するutility by HLD(lca,jump,ances)
		
		getLCA(u, v) ... lca(u, v)を返す。 O(logN)
		dist(u, v) ... (u, v)の間の辺の本数を返す。 O(logN)
		depth(v) ... vの0-indexedの深さを返す。O(1)
		kth_ances(v, k) ... vからk本の辺を根の方向に辿った末の頂点を返す。存在しないなら-1。 O(logN)
		kth_path(s, t, k) ... sからtの方向にk本の辺を辿った末の頂点を返す。存在しないなら-1。 O(logN)
		
		*/
};
