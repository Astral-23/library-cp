struct lca_getter {
    lca_getter(){}

    lca_getter(int _N, int _root) : N(_N), root(_root){
        G.resize(N+1);
        siz.resize(N+1);
        num.resize(N+1, -1);
        nrev.resize(N+1);
        par.resize(N+1);
        head.resize(N+1);

    }
    
    bool initialized = false;
    int N=1;
    int root=1;
    vector<vector<int>> G;
    vector<int> siz;
    vector<int> num;
    vector<int> nrev;
    vector<int> par;
    vector<int> head;

    private:

        int dfs_siz(int now, int prev) {
            siz[now] = 1;
            for(int to : G[now]) {
                if(to == prev) continue;
                siz[now] += dfs_siz(to, now);
            }
            return siz[now];
        }

        void dfs_bunkai(int now, int prev, int hed, int& idx) {
            num[now] = idx;
            nrev[idx] = now;
            idx++;
            par[num[now]] = prev;
            if(hed == -1) hed = num[now];
            head[num[now]] = hed;

            bool f = true;
            for(int i = 0; i < int(G[now].size()); i++) {
                if(num[G[now][i]] != -1) continue;
                if(f) dfs_bunkai(G[now][i], num[now], hed, idx), f = false;
                else dfs_bunkai(G[now][i], num[now], -1, idx);
            }
        }

        void init__() {
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
        void add_edge(int u, int v) {
            G[u].push_back(v);
            G[v].push_back(u);
        }

        void init() {
            initialized = true;
            init__();
        }


        int getLCA(int a, int b) {
            if(!initialized) init();
            a = num[a];
            b = num[b];
            while(true) {
               if(a > b) swap(a, b);
               if(head[a] == head[b]) return nrev[a];
               b = par[head[b]];
            }
        }
};

struct axis_tree {
    axis_tree(int _N, int _root) : N(_N), root(_root){
        G.resize(N+1);
        in.resize(N+1);
        out.resize(N+1);
        lca = lca_getter(N, root);
    }
   

    private:
        int N;
        int root;
        vector<vector<int>> G;
        vector<int> in;
        vector<int> out;
        vector<int> pre_vs;
        lca_getter lca;

    public:
        void add_edge(int u, int v) {
            lca.add_edge(u, v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        void init() {
            lca.init();
            int t = 1;
            auto dfs = [&](auto f, int now, int prev) -> void {
                in[now] = t;
                t++;
                for(auto to : G[now]) if(to != prev) f(f, to, now);
                out[now] = t;
                return;
            };
            dfs(dfs, root, -1);
        }

        int make_tree(vector<int>& V, vector<vector<int>>& G2) {
            if(V.empty()) return -1;
            auto cmp = [&](int i, int j) {
                return in[i] < in[j];
            };
            sort(all0(V), cmp);
            int m = V.size();
            rep(j, 0, m-2) {
                V.push_back(lca.getLCA(V[j], V[j+1]));
            }
    
            sort(all0(V), cmp);
            V.erase(unique(V.begin(), V.end()), V.end());
    
            vector<int> st;
            for(auto v : V) {
                while(st.size()) {
                    int p = st.back();
                    if(in[p] < in[v] && in[v] < out[p]) break;
                    st.pop_back();
                }
                if(st.size()) {
                    G2[st.back()].push_back(v);
                    G2[v].push_back(st.back());
                }
                st.push_back(v);
            }
            pre_vs = V;
            return V[0];
        }

        void clean(vector<vector<int>> &G2) {
            for(auto v : pre_vs) G2[v] = vector<int>();
            pre_vs = vector<int>();
            return;
        }

        /*
        @brief 圧縮木
        頂点集合Vを渡すと、O(|V|log|V|)で、サイズがO(|V|)の圧縮木を返す。

        G2 ... サイズNの、空のvviを渡す。
        使用後、次の圧縮木を作成する前にclean(G2)を呼ぶ。
        make_treeの返り値は仮想の根である。この値が-1の時、圧縮木は空の木である。
        */

};